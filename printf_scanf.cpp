#include<stdio.h>

main(){
//printf******************* 
//int
	printf("%d  %u  %lld  %llu\n",2147483647,4294967211,9223372036854775805,1844674407370955161);
	//longlong use %lld;  
	//unsigned use u;
	//%ld==%d;%lu==%u;
	printf("%x  %X  %#x\n",123456,123456,123456);
	//十六进制输出;
	 
//double	 
	printf("%f %lf\n",1000.123456789,1000.123456789);
	printf("%f\n",1.23);
	//默认6位并四舍五入,不足后补0;
	//%lf==%f; 
	printf("%e  %e\n",1000.123456789,1.234);
	//默认6位四舍五入，不足补0;
	printf("%g  %g  %g\n",0.000000123456789,0.123456789,1.234);
	//最短形式输出double后不补0; 

//*宽度	
	printf("%0*d\n",6,1000);//指定宽度 
	
//flags； +-0 #


//fprintf sprintf
	char str[20];
	 sprintf(str,"%d_abcd!?_%f",123,1.23);//自动以\0结束 
	 printf("%s\n",str);
	 
	 fprintf(stdout,"%d_abcd!?_%f\n",123,1.23);//格式化写入文件(stdout)

//scanf************************
	//scanf()
	//fscanf()
	double f1,f2;
	float f;
	sscanf("1.23456789123 1.23456789123 1.23456789123","%f %f %lf",&f,&f1,&f2);
	printf("%.12f %.12f %.12f\n",f,f1,f2);
	//%f以float形式读入，若指针为double会强制转换出现错误，故double型必须用%lf; （%f!=%lf）
	double ff; 
	sscanf("1.23456789123456789123456789","%lf",&ff);
	printf("%.20f\n",ff);
	//double 有效精度15位 	
	
//其他字符输入/输出

	//fgetc(FILE *stream) 
	//getchar()
	//fgets(char *s, int n, FILE *stream)  会读入换行符 
	//gets(char *s)  不读入换行符 
	
	//fputc(int c, FILE *stream)
	//putchar(int c)
	//fputs(const char *s, FILE *stream)  不包含换行符 
	//puts(const char *s)  自动输出换行符 
	
	//ungetc(int c, FILE *stream)  向 stream写回字符c 
} 

/*
输出： 
2147483647  4294967211  9223372036854775805  1844674407370955161
1e240  1E240  0x1e240
1000.123457 1000.123457
1.230000
1.000123e+003  1.234000e+000
1.23457e-007  0.123457  1.234
001000
123_abcd!?_1.230000
123_abcd!?_1.230000
1.234567880630 0.000000000000 1.234567891230
1.23456789123456790000
*/


