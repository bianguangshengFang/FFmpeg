//
//  main.c
//  ffmpegTestProject
//
//  Created by bianguangsheng on 2017/3/14.
//  Copyright © 2017年 soufunnet. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Rgb-YuvMethod.h"
//加一些注释 声明一些方法 
int simplest_yuv420_split(char *url,int w,int h,int num);
int simplest_yuv444_split(char *url,int w,int h,int num);
int simplest_yuv420_gray(char *url,int w,int h,int num);
int simplest_yun420_halfy(char *url,int w,int h,int num);
int simplest_yun420_border(char *url,int w,int h,int border,int num);
int simplest_yuv420_graybar(int w,int h,float ymin,float ymax,int barnum,char *url_out);
int simplest_yun420_psnr(char *url1,char *url2,int w,int h,int num);
int simplest_rgb24_split(char *url,int w,int h,int num);
int simplest_rgb24_to_yuv420(char *url_in,int w,int h,int num,char *url_out);
int simplest_rgb24_colorbar(int w,int h,char *url_out);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%s ", argv[0] );
//本程序中的函数可以将YUV420P数据中的Y、U、V三个分量分离开来并保存成三个文件
    simplest_yuv420_split("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/miss-america_qcif.yuv", 352, 288, 1);
    //本程序中的函数可以将YUV444P数据中的Y、U、V三个分量分离开来并保存成三个文件
    simplest_yuv444_split("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/miss-america_qcif-0.yuv", 352, 288, 1);
    //本程序中的函数 可以将yun420p文件，y，U,V 三个变量分离出来，别写入三个。y文件
    simplest_yuv420_gray("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/stefan_cif.yuv", 352, 288, 90);
    //笨程序 的函数，可以将yun420 文件， y亮度减半，然后写入一个新文件
    simplest_yun420_halfy("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/stefan_cif.yuv", 352, 288, 90);
    //此方法可以将图像周围加上边框
    
    simplest_yun420_border("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/stefan_cif.yuv", 352, 288,20, 90);
    //此方法可以生成yuv420格式的灰阶测试图
    simplest_yuv420_graybar(352, 288, 0, 255, 10, "/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_grayBar.yuv");
    //计算两个图像的信噪比
    simplest_yun420_psnr("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/stefan_cif.yuv", "/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_half.yuv", 352, 288, 90);
   //分离rgb文件中r g b 分量，并分别写入三个。y文件中
    simplest_rgb24_split("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/rgb.jpg", 500, 500, 1);
    
    //生成一条rgb24 的彩色测试带
    simplest_rgb24_colorbar(1280, 720, "/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/rgbColorbelt.rgb");
    simplest_rgb24_to_yuv420("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/rgbColorbelt.rgb", 1280, 720, 8, "/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/rgbColorbelt.yuv");
    
    
    
    
    
    
    
    printf("Hello, World!\n");
 
    return 0;
}
