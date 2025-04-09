#include "Camera.h"

// the three image buffers to catch every single frame
static uint8 g_Image1[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH];
static uint8 g_Image2[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH];
static uint8 g_Image3[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH];

uint8 (*writing_img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = &g_Image1;		// the image that is currently being received
uint8 (*occupied_img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = 0;				// the image that is currently being processed by CV
uint8 (*latest_img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH] = 0;					// the last image received that hasn't been read yet

uint8* Camera_GetLatest() {
	// if the previous buffer is not released, do not give it another one
	if (occupied_img_ptr != 0)
		return 0;
	// otherwise, return the latest image buffer pointer
	occupied_img_ptr = latest_img_ptr;
	latest_img_ptr = 0;
	return occupied_img_ptr;
}

uint8* Camera_Release(uint8 (*img_ptr)[CAM_IMAGE_HEIGHT][CAM_IMAGE_WIDTH]) {
	// if it attempts to release the correct pointer, then proceed
	if (img_ptr == occupied_img_ptr) {
		occupied_img_ptr = 0;
		return 0;
	}
	// otherwise, do not release
	return occupied_img_ptr;
}

uint8* _Camera_Image_Received(void) {
	uint8 *temp_ptr = writing_img_ptr;
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
			else
				;		// should not happen
		}
	}
	// assign the latest image pointer
	latest_img_ptr = temp_ptr;
	// and return the writing pointer
	return writing_img_ptr;
}
