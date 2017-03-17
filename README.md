# FFmpeg
主要写一些rgb-yuv 像素处理方法文件
主要使用方法：
/本程序中的函数可以将YUV420P数据中的Y、U、V三个分量分离开来并保存成三个文件
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
    
