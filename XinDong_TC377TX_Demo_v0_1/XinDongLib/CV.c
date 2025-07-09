#include "CV.h"
#include <string.h>

//	reference code: none, good luck
//	reference code: TC264_XinDong_Demo_v42/Cpu1_Main.c

// 全局变量
sint16 g_buxian = 0;  // 补线方向判断变量

// 图像预处理：转换为二值化掩码
void CV_PreprocessImage(uint16 (*input_img)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH], 
                       uint16 (*mask)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH]) {
    uint16 y, x;
    
    // 简单的二值化处理：将图像转换为黑白掩码
    for (y = 0; y < CV_IMAGE_HEIGHT; y++) {
        for (x = 0; x < CV_IMAGE_WIDTH; x++) {
            // 如果像素值大于阈值，认为是白色（赛道），否则为黑色（背景）
            if ((*input_img)[y][x] > 128) {
                (*mask)[y][x] = 255;  // 白色
            } else {
                (*mask)[y][x] = 0;    // 黑色
            }
        }
    }
}

// 检查指定区域是否全为黑色
uint16 CV_IsRegionEmpty(uint16 (*mask)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH], 
                      uint16 y, uint16 start_x, uint16 end_x) {
    uint16 x;
    for (x = start_x; x < end_x; x++) {
        if ((*mask)[y][x] == 255) {
            return 0;  // 不是全空
        }
    }
    return 1;  // 全空
}

// 计算指定区域的平均位置
uint16 CV_CalculateAveragePosition(uint16 (*mask)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH], 
                                  uint16 y, uint16 start_x, uint16 end_x) {
    uint16 x;
    uint32 sum = 0;
    uint16 count = 0;
    
    for (x = start_x; x < end_x; x++) {
        if ((*mask)[y][x] == 255) {
            sum += x;
            count++;
        }
    }
    
    if (count == 0) {
        return start_x;  // 如果没有找到白色像素，返回起始位置
    }
    
    return (uint16)(sum / count);
}

// 计算图像中线的偏差（优化版本，直接在原图上处理）
sint16 CV_CalculateMidlineError(uint16 (*input_img)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH], 
                              uint16 (*mask)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH]) {
    uint16 y;
    uint16 half_width = CV_IMAGE_WIDTH / 2;
    uint16 half = half_width;  // 从下往上扫描赛道，最下端取图片中线为分割线
    uint16 left, right, mid;
    sint16 mid_output = 0;
    
    g_buxian = 0;  // 重置补线方向判断变量
    
    // 从下往上扫描
    for (y = CV_IMAGE_HEIGHT - 1; y >= 0; y--) {
        // 检查分割线左端是否有赛道
        if (CV_IsRegionEmpty(mask, y, (half > half_width) ? (half - half_width) : 0, half)) {
            // 分割线左端无赛道
            left = (half > half_width) ? (half - half_width) : 0;
            if (y >= CV_SCAN_START_Y && y <= CV_SCAN_END_Y) {
                g_buxian -= 1;  // 左边补线
            }
        } else {
            // 计算分割线左端平均位置
            left = CV_CalculateAveragePosition(mask, y, 0, half);
        }
        
        // 检查分割线右端是否有赛道
        if (CV_IsRegionEmpty(mask, y, half, (half + half_width < CV_IMAGE_WIDTH) ? (half + half_width) : CV_IMAGE_WIDTH)) {
            // 分割线右端无赛道
            right = (half + half_width < CV_IMAGE_WIDTH) ? (half + half_width) : CV_IMAGE_WIDTH;
            if (y >= CV_SCAN_START_Y && y <= CV_SCAN_END_Y) {
                g_buxian += 1;  // 右边补线
            }
        } else {
            // 计算分割线右端平均位置
            right = CV_CalculateAveragePosition(mask, y, half, CV_IMAGE_WIDTH) + half;
        }
        
        // 计算拟合中点
        mid = (left + right) / 2;
        half = mid;  // 递归，从下往上确定分割线
        
        // 在原图上画出拟合中线（可选，用于调试）
        if (mid < CV_IMAGE_WIDTH) {
            (*input_img)[y][mid] = 255;
        }
        
        // 在指定Y位置提取中点
        if (y == CV_TARGET_Y) {
            mid_output = mid;
        }
    }
    
    // 计算图片中点与指定提取中点的误差
    // error为正数右转，为负数左转
    return (CV_IMAGE_WIDTH / 2) - mid_output;
}

// 中线检测主函数（优化版本，最多使用2个buffer）
CV_Result_t CV_DetectMidline(uint16 (*input_img)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH]) {
    CV_Result_t result;
    static uint16 mask[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH];
    
    // 参数检查
    if (input_img == NULL) {
        result.valid = 0;
        result.error = 0;
        result.image_data = NULL;
        return result;
    }
    
    // 初始化结果
    result.valid = 0;
    result.error = 0;
    result.image_data = (uint16*)input_img;
    
    // 清空掩码缓冲区
    memset(mask, 0, sizeof(mask));
    
    // 图像预处理：生成二值化掩码
    CV_PreprocessImage(input_img, &mask);
    
    // 直接在原图上计算中线偏差（节省一个buffer）
    result.error = CV_CalculateMidlineError(input_img, &mask);
    result.valid = 1;
    
    return result;
}

// 图像处理主函数
CV_Result_t CV_ProcessImage(void) {
    CV_Result_t result;
    uint16 (*img_ptr)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH];
    
    // 初始化结果
    result.valid = 0;
    result.error = 0;
    result.image_data = NULL;
    
    // 获取最新的图像缓冲区
    img_ptr = (uint16 (*)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH])Camera_GetLatest();
    
    if (img_ptr != NULL) {
        // 进行中线检测
        result = CV_DetectMidline(img_ptr);
        
        // 释放图像缓冲区 - 确保在任何情况下都释放
        Camera_Release(img_ptr);
    } else {
        // 如果没有获取到图像缓冲区，返回无效结果
        result.valid = 0;
        result.error = 0;
        result.image_data = NULL;
    }
    
    return result;
}

/*
 * 使用示例：
 * 
 * 在主程序循环中调用：
 * 
 * CV_Result_t cv_result;
 * 
 * // 处理图像并获取中线偏差
 * cv_result = CV_ProcessImage();
 * 
 * if (cv_result.valid) {
 *     // 获取偏差值
 *     sint16 error = cv_result.error;
 *     
 *     // 获取补线方向
 *     sint16 buxian = g_buxian;
 *     
 *     // 根据偏差控制转向
 *     if (error > 0) {
 *         // 右转
 *         // 执行右转控制代码
 *     } else if (error < 0) {
 *         // 左转
 *         // 执行左转控制代码
 *     }
 *     
 *     // 根据补线方向进行额外处理
 *     if (buxian > 0) {
 *         // 右边补线，可能需要特殊处理
 *     } else if (buxian < 0) {
 *         // 左边补线，可能需要特殊处理
 *     }
 * }
 * 
 * 内存优化说明：
 * - 当前实现最多使用2个图像缓冲区：
 *   1. input_img: 来自Camera模块的原始图像
 *   2. mask: 二值化掩码缓冲区（静态分配）
 * - 移除了follow缓冲区，直接在原图上处理
 * - 总内存使用：约90KB (45.12KB × 2) - 注意：由于使用uint16，内存使用量翻倍
 * 
 * 注意：CV_ProcessImage()函数会自动处理图像缓冲区的获取和释放，
 * 无需手动调用Camera_Release()函数。
 * 
 * 如果需要手动管理图像缓冲区，可以使用以下方式：
 * 
 * uint16 (*img_ptr)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH];
 * CV_Result_t result;
 * 
 * // 获取图像缓冲区
 * img_ptr = (uint16 (*)[CV_IMAGE_HEIGHT][CV_IMAGE_WIDTH])Camera_GetLatest();
 * 
 * if (img_ptr != NULL) {
 *     // 进行图像处理
 *     result = CV_DetectMidline(img_ptr);
 *     
 *     // 处理结果...
 *     
 *     // 重要：处理完成后必须释放缓冲区
 *     Camera_Release(img_ptr);
 * }
 */

