//
//  Rgb-YuvMethod.c
//  ffmpegTestProject
//
//  Created by bianguangsheng on 2017/3/17.
//  Copyright © 2017年 soufunnet. All rights reserved.
//

#include "Rgb-YuvMethod.h"
#include <stdlib.h>
typedef enum {
    false=0,
    true
}bool;
//分离yuv 420p像素数据中的Yuv分量函数
/**
 * Split Y, U, V planes in YUV420P file.
 * @param url  Location of Input YUV file.
 * @param w    Width of Input YUV file.
 * @param h    Height of Input YUV file.
 * @param num  Number of frames to process.
 *
 */
int simplest_yuv420_split(char *url,int w,int h,int num) {
    FILE *fp=fopen(url,"rb+");
    FILE *fpy=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_420_y.y", "wb+");
    FILE *fpu=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_420_u.y", "wb+");
    FILE *fpv=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_420_v.y", "wb+");
    unsigned char * pic=(unsigned char *)malloc(w*h*3/2);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp);
        //y
        fwrite(pic, 1, w*h, fpy);
        //u
        fwrite(pic+w*h, 1, w*h/4, fpu);
        //v
        fwrite(pic+w*h*5/4, 1, w*h/4, fpv);
    }
    free(pic);
    fclose(fp);
    fclose(fpy);
    fclose(fpu);
    fclose(fpv);
    
    return 0;
}
//yuv 444p.yuv 文件分离y，u，v，三个分量 ，并保存程三个文件

/**
 yuv 444p.yuv 文件分离y，u，v，三个分量 ，并保存程三个文件
 
 @param url 目标。yuv 文件路径
 @param w yuv文件宽度
 @param h yuv文件的高度
 @param num 帧数
 @return 0
 */
int simplest_yuv444_split(char *url,int w,int h,int num) {
    
    FILE *fp=fopen(url, "rb+");
    FILE *fpy=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_444_y.y", "wb+");
    FILE *fpu=fopen("//Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_444_u.y", "wb+");
    FILE *fpv=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_444_v.y", "wb+");
    unsigned char *pic=(unsigned char *)malloc(w*h*3);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3, fp);
        fwrite(pic, 1, w*h, fpy);
        fwrite(pic+w*h, 1, w*h, fpu);
        fwrite(pic+w*h*2, 1, w*h, fpv);
        
    }
    free(pic);
    fclose(fp);
    fclose(fpy);
    fclose(fpu);
    fclose(fpv);
    return 0;
}
//将yuv 420p 像素数据去掉颜色，变成纯粹的灰度，函数的代码如下

/**
 将yuv 420p 像素数据去掉颜色，变成纯粹的灰度，函数的代码如下
 
 @param url yuv文件的路径
 @param w 在播放器中屏幕的宽度
 @param h 在播放器屏幕中展示的高度
 @param num 文件总帧数
 @return 0，结束标志
 */
int simplest_yuv420_gray(char *url,int w,int h,int num){
    FILE *fp=fopen(url,"rb+");
    FILE *fpgray=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_gray.yuv","wb+");
    unsigned char *pic=(unsigned char *)malloc(w*h*3/2);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp);
        //将u，v 分量全部置为gray，u，为u*h/4，v 也是，U*V/4;
        memset(pic+w*h,128,(unsigned long)(w*h/2));
        fwrite(pic,1,w*h*3/2, fpgray);
    }
    free(pic);
    fclose(fp);
    fclose(fpgray);
    printf("end here");
    return 0;
    
}
//将视频的亮度减少一半
int simplest_yun420_halfy(char *url,int w,int h,int num){
    FILE *fp=fopen(url, "rb+");
    FILE *fphalfy=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_half.yuv", "wb+");
    unsigned char *pic=(unsigned char *)malloc(w*h*3/2);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp);
        //halfy
        for (int j=0; j<w*h; j++) {
            unsigned char temp=pic[j]/2;
            pic[j]=temp;
            
        }
        fwrite(pic, 1, w*h*3/2, fphalfy);
    }
    free(pic);
    fclose(fp);
    fclose(fphalfy);
    return 0;
}
//将YUV420P像素数据的周围加上边框

/**
 将YUV420P像素数据的周围加上边框
 
 @param url yuv文件路径
 @param w 播放器展示宽度
 @param h 播放器展示高度
 @param border 播放器边缘宽度
 @param num 帧数
 @return 0
 */
int simplest_yun420_border(char *url,int w,int h,int border,int num){
    FILE *fp=fopen(url, "rb+");
    FILE *fpBorder=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_border.yuv", "wb+");
    unsigned char *pic=(unsigned char *)malloc(w*h*3/2);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3/2, fp);
        //Y 边框部分弄为255 亮度最亮。
        for (int j=0; j<h; j++) {
            for (int k=0; k<w;k++) {
                if (k<border||k>w-border||j<border||j>h-border) {
                    //
                    pic[j*w+k]=255;
                }
            }
        }
        fwrite(pic, 1, w*h*3/2, fpBorder);
    }
    free(pic);
    fclose(fp);
    fclose(fpBorder);
    
    return 0;
}
//生成yuv420p格式的灰阶测试图

/**
 生成yuv420p格式的灰阶测试图
 
 @param w 使用播放器展示屏幕宽度
 @param h 使用播放器展示屏幕高度
 @param ymin 亮度最小值 0--255
 @param ymax 亮度最大值 0--255
 @param barnum 灰度测试bar数目
 @param url_out 输出的存放测试文件路径
 @return 0
 */
int simplest_yuv420_graybar(int w,int h,float ymin,float ymax,int barnum,char *url_out){
    float barWidth;//单个bar的宽度
    float lum_inc;
    unsigned char lum_temp;
    int uv_width,uv_height;
    FILE *fp=NULL;
    unsigned char *data_y=NULL;
    unsigned char *data_u=NULL;
    unsigned char *data_v=NULL;
    int t=0,i=0,j=0;
    barWidth=w/barnum;
    lum_inc=(ymax-ymin)/(barnum-1);
    uv_width=w/2;
    uv_height=h/2;
    data_y=(unsigned char *)malloc(w*h);
    data_u=(unsigned char *)malloc(uv_width *uv_height);
    data_v=(unsigned char *)malloc(uv_width *uv_height);
    if ((fp=fopen(url_out, "wb+"))==NULL) {
        printf("error:cannot create file");
        return -1;
    }
    //output info
    printf("y u ,v value from picture's leftto right\n");
    for (t=0; t<w/barWidth; t++) {
        lum_temp=ymin+(t*lum_inc);
        printf("%3d,128,128\n",lum_temp);
        
    }
    //gen  ydata
    for (j=0; j<h; j++) {
        for (i=0; i<w; i++) {
            t=i/barWidth;
            lum_temp=ymin+(char)(t*lum_inc);
            data_y[j*w+i]=lum_temp;
            
        }
    }
    // gen u data
    for (j=0; j<uv_height; j++) {
        for (i=0; i<uv_width; i++) {
            data_u[j*uv_width+i]=128;
        }
    }
    //gen v data
    for (j=0; j<uv_height; j++) {
        for (i=0; i<uv_width; i++) {
            data_v[j*uv_width+i]=128;
        }
    }
    fwrite(data_y, w*h, 1, fp);
    fwrite(data_u, uv_width*uv_height, 1, fp);
    fwrite(data_v, uv_width*uv_height, 1, fp);
    fclose(fp);
    free(data_u);
    free(data_v);
    free(data_y);
    
    
    return 0;
}
//计算两个yuv420像素数据的psnr 峰值信噪比；

/**
 计算两个yuv420像素数据的psnr 峰值信噪比
 
 @param url1 yuv文件1路径
 @param url2 yuv文件2路径
 @param w 视频展示宽度
 @param h 视频展示高度
 @param num 帧数
 @return 0
 */
int simplest_yun420_psnr(char *url1,char *url2,int w,int h,int num){
    FILE *fp1=fopen(url1, "rb+");
    FILE *fp2=fopen(url2, "rb+");
    unsigned char *pic1=(unsigned char *)malloc(w*h);
    unsigned char *pic2=(unsigned char *)malloc(w*h);
    for (int i=0; i<num; i++) {
        fread(pic1, 1, w*h, fp1);
        fread(pic2, 1, w*h, fp2);
        double mse_sum=0,mse=0,pnsr=0;
        for (int j=0; j<w*h; j++) {
            mse_sum+=pow((double)(pic1[j]-pic2[j]),2);
            
        }
        mse=mse_sum/(w*h);
        pnsr=10*log10(255.0*255.0/mse);
        printf("pnsr:%5.3f\n",pnsr);
        fseek(fp1, w*h/2, SEEK_CUR);
        fseek(fp2, w*h/2, SEEK_CUR);
        
    }
    fclose(fp2);
    fclose(fp1);
    free(pic2);
    free(pic1);
    
    
    return 0;
}

//分离rgb像素数据中的rgb分量
int simplest_rgb24_split(char *url,int w,int h,int num){
    FILE *fp=fopen(url, "rb+");
    FILE *fpr=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_r.y", "wb+");
    FILE *fpg=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_g.y", "wb+");
    FILE *fpb=fopen("/Users/bianguangsheng/Desktop/ffmpegStudyProject/ffmpegTestProject/ffmpegTestProject/output_b.y", "wb+");
    unsigned char *pic=(unsigned char *)malloc(w*h*3);
    for (int i=0; i<num; i++) {
        fread(pic, 1, w*h*3, fp);
        for (int j=0; j<w*h*3; j=j+3) {
            //r
            fwrite(pic+j,1,1,fpr);
            //g
            fwrite(pic+j+1, 1, 1, fpg);
            //b
            fwrite(pic+j+2, 1, 1, fpb);
        }
    }
    
    
    
    
    
    return 0;
}
//将rgb24格式图像数据封装成bmp图像数据
/**
 * Convert RGB24 file to BMP file
 * @param rgb24path    Location of input RGB file.
 * @param width        Width of input RGB file.
 * @param height       Height of input RGB file.
 * @param bmppath      Location of Output BMP file.
 */
int simplest_rgb24_to_bmp(const char *rgb24path,int width,int height,const char *bmppath){
    
    typedef struct {
        long imageSize;//文件大小
        int blank;
        long startPosition;//位图文件的偏移量
    }BmpHead;
    
    typedef struct {
        long length; //该结构大小，字节为单位
        long width;//图形宽度以象素为单位
        long height;//图形高度以象素为单位
        unsigned short colorPlane;//目标设备的级别，必须为1
        unsigned short bitColor;
        long zipFormat;//颜色深度，每个象素所需要的位数
        long realSize;//位图的大小，以字节为单位
        long xPels;//位图水平分辨率，每米像素数
        long yPels; //位图垂直分辨率，每米像素数
        long colorUse;//位图实际使用的颜色表中的颜色数
        long colorImporttant; //位图显示过程中重要的颜色数
    }InfoHead;
    int i=0,j=0;
    BmpHead m_BMPHeader={0};
    InfoHead m_BMPInfoHeader={0};
    char bfType[2]={'B','M'};
    int header_size=sizeof(bfType)+sizeof(InfoHead)+sizeof(BmpHead);
    unsigned char *rgb24_buffer=NULL;
    FILE *fp_rgb24=NULL;
    FILE *fp_bmp=NULL;
    if ((fp_rgb24=fopen(rgb24path, "rb+"))==NULL) {
        printf("error:cannot open input rgb24 file \n");
        return -1;
        
    }
    if ((fp_bmp=fopen(bmppath, "wb+"))==NULL) {
        printf("error: cannot open out bmp file \n");
        return -1;
    }
    //放rgb24 数据
    rgb24_buffer=(unsigned char *)malloc(width *height*3);
    fread(rgb24_buffer, 1, width*height*3, fp_rgb24);
    m_BMPHeader.imageSize=width*height*3+header_size;
    m_BMPHeader.startPosition=header_size;
    m_BMPInfoHeader.length=sizeof(InfoHead);
    m_BMPInfoHeader.width=width;
    m_BMPInfoHeader.height= - height;
    m_BMPInfoHeader.colorPlane=1;
    m_BMPInfoHeader.bitColor=24;
    m_BMPInfoHeader.realSize=3*width*height;
    fwrite(bfType, 1, sizeof(bfType), fp_bmp);
    fwrite(&m_BMPHeader, 1, sizeof(m_BMPHeader), fp_bmp);
    fwrite(&m_BMPInfoHeader, 1, sizeof(m_BMPInfoHeader), fp_bmp);
    
    //BMP save R1|G1|B1,R2|G2|B2 as B1|G1|R1,B2|G2|R2
    //It saves pixel data in Little Endian
    //So we change 'R' and 'B'
    for (j=0; j<width; j++) {
        for (i=0; i<width; i++) {
            char temp=rgb24_buffer[(j*width+i)*3+2];
            rgb24_buffer[(j*width+i)*3+2]=rgb24_buffer[(j*width+i)*3+0];
            rgb24_buffer[(j*width+i)*3+0]=temp;
        }
    }
    fwrite(rgb24_buffer, 3*width*height, 1, fp_bmp);
    fclose(fp_rgb24);
    fclose(fp_bmp);
    free(rgb24_buffer);
    printf("finish generate %s\n",bmppath);
    
    
    
    return 0;
    
}
//截取一段值
unsigned char clip_value(unsigned char x,unsigned char min_val,unsigned char max_val){
    if (x<min_val) {
        return min_val;
    }
    else if (x>max_val){
        return max_val;
    }
    else{
        return x;
    }
    
}

//RGB TO YUV420

/**
 本程序实现了RGB到YUV的转换公式
 Y= 0.299*R+0.587*G+0.114*B
 U=-0.147*R-0.289*G+0.463*B
 V= 0.615*R-0.515*G-0.100*B
 
 
 */
bool RGB24_To_Yuv420(unsigned char *RgbBuf,int w,int h,unsigned char *yuvBuf){
    unsigned char *ptrY,*ptrU,*ptrV,*ptrRgb;
    memset(yuvBuf, 0, w*h*3/2);
    ptrY=yuvBuf;
    ptrU=yuvBuf+w*h;
    ptrV=ptrU+w*h/4;
    unsigned char y,u,v,r,g,b;
    for (int j=0; j<h; j++) {
        ptrRgb=RgbBuf +w*j*3;
        for (int i=0; i<w; i++) {
            r=*(ptrRgb++);
            g=*(ptrRgb++);
            b=*(ptrRgb++);
            y=(unsigned char)((66*r+129*g+25*b+128)>>8)+16;
            u=(unsigned char)((-38*r-74*g+112*b+128)>>8)+128;
            v=(unsigned char)((112 *r-94*g-18*b+128)>>8)+128;
            *(ptrY++)=clip_value(y, 0, 255);
            if (j%2==0&&i%2==0) {
                *(ptrU++)=clip_value(u, 0, 255);
            }else{
                if (i%2==0) {
                    *(ptrV++)=clip_value(v, 0, 255);
                }
            }
        }
    }
    
    
    
    return true;
}

/**
 把rgb文件转为yuv420文件
 
 @param url_in rgb文件本地路径
 @param w 播放器展示视频的宽度
 @param h 播放器展示视频的高度
 @param num 帧数
 @param url_out 输出的yuv420 文件
 @return 0
 */
int simplest_rgb24_to_yuv420(char *url_in,int w,int h,int num,char *url_out){
    FILE *fp=fopen(url_in, "rb+");
    FILE *fpout=fopen(url_out, "wb+");
    //开辟两个空间
    unsigned char *pic_rgb24=(unsigned char *)malloc(w*h*3);
    unsigned char *pic_yuv420=(unsigned char *)malloc(w*h*3/2);
    for (int i=0; i<num; i++) {
        fread(pic_rgb24, 1, w*h*3, fp);
        RGB24_To_Yuv420(pic_rgb24, w, h, pic_yuv420);
        //写入输出文件里
        fwrite(pic_yuv420, 1, w*h*3/2, fpout);
        
    }
    free(pic_yuv420);
    free(pic_rgb24);
    fclose(fp);
    fclose(fpout);
    
    
    
    
    
    
    return 0;
}

//生成一条rgb24 格式的彩色测试带
int simplest_rgb24_colorbar(int w,int h,char *url_out) {
    unsigned char *data=NULL;
    int barwidth;
    //    char filename[100]={0};
    FILE *fp=NULL;
    int i=0,j=0;
    data=(unsigned char *)malloc(w*h*3);
    barwidth=w/8;
    if ((fp=fopen(url_out, "wb+"))==NULL) {
        printf("error:cannot create file");
        return -1;
    }
    for (j=0; j<h; j++) {
        for (i=0; i<w; i++) {
            int barnum=i/barwidth;
            switch (barnum) {
                case 0:
                {
                    //白
                    //r 的y 置为255 白色
                    data[(j*w+i)*3+0]=255;
                    //g的y 置为255 白色
                    data[(j*w+i)*3+1]=255;
                    //b的y 置为255 白色
                    data[(j*w+i)*3+2]=255;
                    break;
                    
                    
                }
                case 1:{
                    //黄色
                    data[(j*w+i)*3+0]=255;
                    data[(j*w+i)*3+1]=255;
                    data[(j*w+i)*3+2]=0;
                    break;
                    
                }
                case 2:{
                    //青绿
                    data[(j*w+i)*3+0]=0;
                    data[(j*w+i)*3+1]=255;
                    data[(j*w+i)*3+2]=255;
                    break;
                }
                case 3:{
                    //绿色
                    data[(j*w+i)*3+0]=0;
                    data[(j*w+i)*3+1]=255;
                    data[(j*w+i)*3+2]=0;
                    break;
                }
                case 4:{
                    //紫色
                    data[(j*w+i)*3+0]=255;
                    data[(j*w+i)*3+1]=0;
                    data[(j*w+i)*3+2]=255;
                    break;
                }
                case 5:{
                    //红色
                    data[(j*w+i)*3+0]=255;
                    data[(j*w+i)*3+1]=0;
                    data[(j*w+i)*3+2]=0;
                    break;
                }
                case 6:{
                    //蓝色
                    data[(j*w+i)*3+0]=0;
                    data[(j*w+i)*3+1]=0;
                    data[(j*w+i)*3+2]=255;
                    break;
                }
                case 7:{
                    //黑色
                    data[(j*w+i)*3+0]=0;
                    data[(j*w+i)*3+1]=0;
                    data[(j*w+i)*3+2]=0;
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    free(data);
    fclose(fp);
    
    
    return 0;
    
}





