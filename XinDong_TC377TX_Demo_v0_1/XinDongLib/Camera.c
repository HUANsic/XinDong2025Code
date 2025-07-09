#include "Camera.h"
#include "EI2C.h"

// (DO NOT EXTERN!!!) the three image buffers to catch every single frame
// each only writable by either Camera.c OR cv.c (static just to possess their uniqueness)
static uint16 g_Image1[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH];
static uint16 g_Image2[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH];
static uint16 g_Image3[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH];

uint16 (*writing_img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = &g_Image1;		// the image that is currently being received
uint16 (*occupied_img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = 0;				// the image that is currently being processed by CV
uint16 (*latest_img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = 0;				// the last image received that hasn't been read yet

void* Camera_GetLatest(void) {
	// if the previous buffer is not released, do not give it another one
	if (occupied_img_ptr != 0)
		return 0;
	// otherwise, return the latest image buffer pointer
	occupied_img_ptr = latest_img_ptr;
	latest_img_ptr = 0;
	return occupied_img_ptr;
}

void* Camera_Release(void (*img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH]) {
	// if it attempts to release the correct pointer, then proceed
	if (img_ptr == occupied_img_ptr) {
		occupied_img_ptr = 0;
		return 0;
	}
	// otherwise, do not release
	return occupied_img_ptr;
}

void* _Camera_Image_Received(void) {
	uint16 (*temp_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = writing_img_ptr;
	// if there is a buffer occupied, then there is only one buffer available
	if (occupied_img_ptr != 0) {
		if (occupied_img_ptr == &g_Image1) {
			if (writing_img_ptr == &g_Image2)
				writing_img_ptr = &g_Image3;
			else
				writing_img_ptr = &g_Image2;
		} else if (occupied_img_ptr == &g_Image2) {
			if (writing_img_ptr == &g_Image1)
				writing_img_ptr = &g_Image3;
			else
				writing_img_ptr = &g_Image1;
		} else if (occupied_img_ptr == &g_Image3) {
			if (writing_img_ptr == &g_Image1)
				writing_img_ptr = &g_Image2;
			else
				writing_img_ptr = &g_Image1;
		} else {		// no image is occupied
			if (writing_img_ptr == &g_Image1)
				writing_img_ptr = &g_Image2;
			else if (writing_img_ptr == &g_Image2)
				writing_img_ptr = &g_Image3;
			else if (writing_img_ptr == &g_Image3)
				writing_img_ptr = &g_Image1;
		}
	}
	// assign the latest image pointer
	latest_img_ptr = temp_ptr;
	// and return the writing pointer
	return writing_img_ptr;
}
