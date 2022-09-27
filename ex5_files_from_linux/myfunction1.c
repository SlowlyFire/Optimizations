//312491616 Gal Giladi
#include <stdbool.h> 
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b) 

//sizeof(pixel) is 3
typedef struct {
   unsigned char red;
   unsigned char green;
   unsigned char blue;
} pixel;

typedef struct {
    int red;
    int green;
    int blue;
    // int num;
} pixel_sum;

void myfunction(Image *image, char* srcImgpName, char* blurRsltImgName, char* sharpRsltImgName, char* filteredBlurRsltImgName, char* filteredSharpRsltImgName, char flag) {

	if (flag == '1') {	
		// blur image
		//instead of doConvolution(image, blurKernel, 9, false)
			//int t1= m*m;
			//int t1=image->sizeX * image->sizeY;
		  int z= m * n *sizeof(pixel);
			//pixel* pixelsImg = malloc(z);

			pixel* pixelsImg = (pixel*) image->data;
			pixel* backupOrg = malloc(z);

			pixel* backupPointer = backupOrg;
			pixel* pixelsImgPointer = pixelsImg;

			int row, col;
			register int t2=0;
            register int t3;

            // copy pixel
        int loop_size = n*m;
        int i;
        for ( i= 0; i < loop_size; ++i) {
            (*(backupPointer)) = (*(pixelsImgPointer));
            pixelsImgPointer++;
            backupPointer++;
        }

		/* Apply the kernel over each pixel.
		* Ignore pixels where the kernel exceeds bounds. These are pixels with row index smaller than 1 and/or
		* column index smaller than 1 */
			int j;
			int len = m - 1;
			pixel_sum sum;
            t2=m;
            pixel p1, p2, p3, p4, p5, p6, p7, p8, p9;
			for (i = 1 ; i < len; ++i) {
				for (j =  1 ; j < len ; ++j) {
					t3=t2+j;
					// Applies kernel for pixel at (i,j)
					//Initializes all fields of sum to 0
					sum.red = sum.green = sum.blue = 0;
					// apply kernel on pixel at [ii,jj]

                    p1 = *(backupOrg + t3-m-1);
                    p2 = *(backupOrg+ t3-m);
                    p3 = *(backupOrg + t3+1-m);
                    p4 = *(backupOrg + t3-1);
                    p5 = *(backupOrg+t3);
                    p6 = *(backupOrg+t3+1);
                    p7 = *(backupOrg+t3+m-1);
                    p8 = *(backupOrg+t3+m);
                    p9 = *(backupOrg+t3+m+1);

                    sum.red = ((((int) p1.red)+ ((int) p2.red)+ ((int) p3.red ) + ((int) p4.red) + ((int) p5.red)  +((int) p6.red) + ((int) p7.red)  + ((int) p8.red)  +((int) p9.red)))/9;
                    sum.green =((((int) p1.green)+ ((int) p2.green)+ ((int) p3.green) + ((int) p4.green) + ((int) p5.green)  +((int) p6.green) + ((int) p7.green)  + ((int) p8.green)  +((int) p9.green)))/9;
                    sum.blue = ((((int) p1.blue)+ ((int) p2.blue)+ ((int) p3.blue ) + ((int) p4.blue) + ((int) p5.blue) + ((int) p6.blue) + ((int) p7.blue) + ((int) p8.blue)  +((int) p9.blue)))/9;

					//sum.red += ((int) backupOrg[t3-m-1].red)+((int) backupOrg[t3-m].red)+((int) backupOrg[t3+1-m].red)+((int) backupOrg[t3-1].red)+((int) backupOrg[t3].red)+((int) backupOrg[t3+1].red)+((int) backupOrg[t3+m-1].red)+((int) backupOrg[t3+m].red)+((int) backupOrg[t3+m+1].red);
					//sum.green += ((int) backupOrg[t3-m-1].green)+((int) backupOrg[t3-m].green)+((int) backupOrg[t3+1-m].green)+((int) backupOrg[t3-1].green)+((int) backupOrg[t3].green)+((int) backupOrg[t3+1].green)+((int) backupOrg[t3+m-1].green)+((int) backupOrg[t3+m].green)+((int) backupOrg[t3+m+1].green);
					//sum.blue += ((int) backupOrg[t3-m-1].blue)+((int) backupOrg[t3-m].blue)+((int) backupOrg[t3+1-m].blue)+((int) backupOrg[t3-1].blue)+((int) backupOrg[t3].blue)+((int) backupOrg[t3+1].blue)+((int) backupOrg[t3+m-1].blue)+((int) backupOrg[t3+m].blue)+((int) backupOrg[t3+m+1].blue);
					//sum.red = sum.red / 9;
					//sum.green = sum.green / 9;
					//sum.blue = sum.blue / 9;

					// truncate each pixel's color values to match the range [0,255]
					pixelsImg[t3].red = (unsigned char) (min(max(sum.red, 0), 255));
					pixelsImg[t3].green = (unsigned char) (min(max(sum.green, 0), 255));
					pixelsImg[t3].blue = (unsigned char) (min(max(sum.blue, 0), 255));
					//pixelsImg[t3] = current_pixel;
				}
				//int t2=i*m;
				t2+=m;
			}

		// write result image to file
		writeBMP(image, srcImgpName, blurRsltImgName);	

		// sharpen the resulting image
		//instead of doConvolution(image, sharpKernel, 1, false);
		//pixel* backupOrg2 = malloc(z);

		backupPointer = backupOrg;
        pixelsImgPointer = pixelsImg;
		//copyPixels
        for (i = 0; i < loop_size; ++i) {
            (*(backupPointer)) = (*(pixelsImgPointer));
            pixelsImgPointer++;
            backupPointer++;
        }

		/* Apply the kernel over each pixel.
		* Ignore pixels where the kernel exceeds bounds. These are pixels with row index smaller than 1 and/or
		* column index smaller than 1 */
        t2=m;
		for (i = 1 ; i < len; i++) {
			for (j =  1 ; j < len ; j++) {
				t3=t2+j;
				// Applies kernel for pixel at (i,j)
				//	instead of kernelApply function
				//Initializes all fields of sum to 0
				sum.red = sum.green = sum.blue = 0;
				// apply kernel on pixel at [ii,jj]

                p1 = *(backupOrg + t3-m-1);
                p2 = *(backupOrg+ t3-m);
                p3 = *(backupOrg + t3+1-m);
                p4 = *(backupOrg + t3-1);
                p5 = *(backupOrg+t3);
                p6 = *(backupOrg+t3+1);
                p7 = *(backupOrg+t3+m-1);
                p8 = *(backupOrg+t3+m);
                p9 = *(backupOrg+t3+m+1);


                sum.red  = -((int) p1.red)- ((int) p2.red)- ((int) p3.red ) - ((int) p4.red)  -((int) p6.red) -((int) p7.red) - ((int) p8.red)  -((int) p9.red) + (9 * ((int) p5.red));
                sum.green = -(((int) p1.green))- (((int) p2.green) )- ((int) p3.green) - ((int) p4.green)-((int) p6.green) - ((int) p7.green)  - ((int) p8.green)  -((int) p9.green) + (9 * ((int) p5.green));
                sum.blue = -((int) p1.blue)-((int) p2.blue)-((int) p3.blue ) -((int) p4.blue) -((int) p6.blue) -((int) p7.blue)  -((int) p8.blue)  -((int) p9.blue)+ (9 * ((int) p5.blue));

				//sum.red -= ((int) backupOrg[t3-m-1].red)+((int) backupOrg[t3-m].red)+((int) backupOrg[t3+1-m].red)+((int) backupOrg[t3-1].red)-((int) backupOrg[t3].red)*9+((int) backupOrg[t3+1].red)+((int) backupOrg[t3+m-1].red)+((int) backupOrg[t3+m].red)+((int) backupOrg[t3+m+1].red);
				//sum.green -= ((int) backupOrg[t3-m-1].green)+((int) backupOrg[t3-m].green)+((int) backupOrg[t3+1-m].green)+((int) backupOrg[t3-1].green)-((int) backupOrg[t3].green)*9+((int) backupOrg[t3+1].green)+((int) backupOrg[t3+m-1].green)+((int) backupOrg[t3+m].green)+((int) backupOrg[t3+m+1].green);
				//sum.blue -= ((int) backupOrg[t3-m-1].blue)+((int) backupOrg[t3-m].blue)+((int) backupOrg[t3+1-m].blue)+((int) backupOrg[t3-1].blue)-((int) backupOrg[t3].blue)*9+((int) backupOrg[t3+1].blue)+((int) backupOrg[t3+m-1].blue)+((int) backupOrg[t3+m].blue)+((int) backupOrg[t3+m+1].blue);
						
				// truncate each pixel's color values to match the range [0,255]
				pixelsImg[t3].red = (unsigned char) (min(max(sum.red, 0), 255));
				pixelsImg[t3].green = (unsigned char) (min(max(sum.green, 0), 255));
				pixelsImg[t3].blue = (unsigned char) (min(max(sum.blue, 0), 255));
				//pixelsImg[t3] = current_pixel;
			}
			//int t2=i*m;
            t2+=m;
		}

		free(backupOrg);

			
		// write result image to file
		writeBMP(image, srcImgpName, sharpRsltImgName);	
	} else {
		// apply extermum filtered kernel to blur image
		//instead of doConvolution(image, blurKernel, 7, true);
		//int t1= m*m;
		int z= m * n *sizeof(pixel);
		pixel* pixelsImg = (pixel*) image->data;
		pixel* backupOrg = malloc(z);

        pixel* backupPointer = backupOrg;
        pixel* pixelsImgPointer = pixelsImg;
		register int row;
		register int col;
		register int t2=0;
        register int t3;

        int loop_size = n*m;
        //copyPixels
        int jj;
        for ( jj = 0; jj < loop_size; ++jj) {
            (*(backupPointer)) = (*(pixelsImgPointer));
            pixelsImgPointer++;
            backupPointer++;
        }

	/* Apply the kernel over each pixel.
	* Ignore pixels where the kernel exceeds bounds. These are pixels with row index smaller than 1 and/or
	* column index smaller than 1 */
		int i, j;
		int len = m - 1;
        pixel_sum sum;
		int min_row, min_col, max_row, max_col;
		pixel loop_pixel;
		int t4;
		t3=m;
        register int sum_p;
		for (i = 1 ; i < len; ++i) {
			for (j =  1 ; j < len ; ++j) {
					// Applies kernel for pixel at (i,j)
					//	instead of kernelApply function	
					int min_intensity = 766; // arbitrary value that is higher than maximum possible intensity, which is 255*3=765
					int max_intensity = -1; // arbitrary value that is lower than minimum possible intensity, which is 0
					//Initializes all fields of sum to 0
					sum.red = sum.green = sum.blue = 0;
                    // apply kernel on pixel at [ii,jj]
					t2=t3-m+j-1;
                	sum.red += ((int) backupOrg[t2].red)+((int) backupOrg[t2+1].red)+((int) backupOrg[t2+2].red)+((int) backupOrg[t2+m].red)+((int) backupOrg[t2+m+1].red)+((int) backupOrg[t2+m+2].red)+((int) backupOrg[t2+m+m].red)+((int) backupOrg[t2+m+m+1].red)+((int) backupOrg[t2+m+m+2].red);
					sum.green += ((int) backupOrg[t2].green)+((int) backupOrg[t2+1].green)+((int) backupOrg[t2+2].green)+((int) backupOrg[t2+m].green)+((int) backupOrg[t2+m+1].green)+((int) backupOrg[t2+m+2].green)+((int) backupOrg[t2+m+m].green)+((int) backupOrg[t2+m+m+1].green)+((int) backupOrg[t2+m+m+2].green);
					sum.blue += ((int) backupOrg[t2].blue)+((int) backupOrg[t2+1].blue)+((int) backupOrg[t2+2].blue)+((int) backupOrg[t2+m].blue)+((int) backupOrg[t2+m+1].blue)+((int) backupOrg[t2+m+2].blue)+((int) backupOrg[t2+m+m].blue)+((int) backupOrg[t2+m+m+1].blue)+((int) backupOrg[t2+m+m+2].blue);

					loop_pixel = backupOrg[t2];
                    sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
                    if (sum_p<= min_intensity) {
								min_intensity = sum_p;
								min_row = i-1;
								min_col = j-1;
						}
						if (sum_p> max_intensity) {
								max_intensity = sum_p;
								max_row = i-1;
								max_col = j-1;
						}
					
					t2++;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p <= min_intensity) {
								min_intensity =sum_p;
								min_row = i-1;
								min_col = j;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i-1;
								max_col = j;
						}
					
					t2++;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p <= min_intensity) {
								min_intensity = sum_p;
								min_row = i-1;
								min_col = j+1;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i-1;
								max_col = j+1;
						}
			
					t2=t2+m-2;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p <= min_intensity) {
								min_intensity = sum_p;
								min_row = i;
								min_col = j-1;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i;
								max_col = j-1;
						}

					t2++;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p <= min_intensity) {
								min_intensity = sum_p;
								min_row = i;
								min_col = j;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i;
								max_col = j;
						}
					

					t2++;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p<= min_intensity) {
								min_intensity = sum_p;
								min_row = i;
								min_col = j+1;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i;
								max_col = j+1;
						}
					
					t2=t2+m-2;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p<= min_intensity) {
								min_intensity = sum_p;
								min_row = i+1;
								min_col = j-1;
						}
						if (sum_p> max_intensity) {
								max_intensity = sum_p;
								max_row = i+1;
								max_col = j-1;
						}

					t2++;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p <= min_intensity) {
								min_intensity = sum_p;
								min_row = i+1;
								min_col = j;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i+1;
								max_col = j;
						}
					
					t2++;
					loop_pixel = backupOrg[t2];
                sum_p = (((int) loop_pixel.red) + ((int) loop_pixel.green) + ((int) loop_pixel.blue));
						if (sum_p<= min_intensity) {
								min_intensity = sum_p;
								min_row = i+1;
								min_col = j+1;
						}
						if (sum_p > max_intensity) {
								max_intensity = sum_p;
								max_row = i+1;
								max_col = j+1;
						}

					// filter out min and max
					//Sums pixel values, scaled by given weight
					int result3=min_row*m+min_col;
					int result4=max_row*m+max_col;

					sum.red -= ((int) backupOrg[result3].red+(int) backupOrg[result4].red);
					sum.green -= ((int) backupOrg[result3].green+(int) backupOrg[result4].green);
					sum.blue -= ((int) backupOrg[result3].blue+(int) backupOrg[result4].blue);

				// assign kernel's result to pixel at [i,j]
				// divide by kernel's weight
				sum.red = sum.red / 7;
				sum.green = sum.green / 7;
				sum.blue = sum.blue / 7;

				// truncate each pixel's color values to match the range [0,255]
				t4=t3+j;
				pixelsImg[t4].red = (unsigned char) (min(max(sum.red, 0), 255));
				pixelsImg[t4].green = (unsigned char) (min(max(sum.green, 0), 255));
				pixelsImg[t4].blue = (unsigned char) (min(max(sum.blue, 0), 255));
			}
			//t3=i*m;
			t3+=m;
		}

		//free(backupOrg);

		// write result image to file
		writeBMP(image, srcImgpName, filteredBlurRsltImgName);

		// sharpen the resulting image
		//instead of doConvolution(image, sharpKernel, 1, false);
		//pixel* pixelsImg2 = malloc(z);
		// pixel* pixelsImg2 = (pixel*) image->data;
		// pixel* backupOrg = malloc(z);

        //copyPixels
        //int loop_size = n*m;
        backupPointer = backupOrg;
        pixelsImgPointer = pixelsImg;
        int ii;
        for (ii = 0; ii < loop_size; ++ii) {
                (*(backupPointer)) = (*(pixelsImgPointer));
                pixelsImgPointer++;
                backupPointer++;
        }

	/* Apply the kernel over each pixel.
	* Ignore pixels where the kernel exceeds bounds. These are pixels with row index smaller than 1 and/or
	* column index smaller than 1 */
        t3=0;
		for (i = 1 ; i < len; ++i) {
			//int t3=i*m;
            t3+=m;
			for (j =  1 ; j < len ; ++j) {
				// Applies kernel for pixel at (i,j)
				//	instead of kernelApply function
				//Initializes all fields of sum to 0
				sum.red = sum.green = sum.blue = 0;

				// apply kernel on pixel at [ii,jj]
				t2=t3-m+j-1;
                sum.red -= ((int) backupOrg[t2].red)+((int) backupOrg[t2+1].red)+((int) backupOrg[t2+2].red)+((int) backupOrg[t2+m].red)-((int) backupOrg[t2+m+1].red)*9+((int) backupOrg[t2+m+2].red)+((int) backupOrg[t2+m+m].red)+((int) backupOrg[t2+m+m+1].red)+((int) backupOrg[t2+m+m+2].red);
				sum.green -= ((int) backupOrg[t2].green)+((int) backupOrg[t2+1].green)+((int) backupOrg[t2+2].green)+((int) backupOrg[t2+m].green)-((int) backupOrg[t2+m+1].green)*9+((int) backupOrg[t2+m+2].green)+((int) backupOrg[t2+m+m].green)+((int) backupOrg[t2+m+m+1].green)+((int) backupOrg[t2+m+m+2].green);
				sum.blue -= ((int) backupOrg[t2].blue)+((int) backupOrg[t2+1].blue)+((int) backupOrg[t2+2].blue)+((int) backupOrg[t2+m].blue)-((int) backupOrg[t2+m+1].blue)*9+((int) backupOrg[t2+m+2].blue)+((int) backupOrg[t2+m+m].blue)+((int) backupOrg[t2+m+m+1].blue)+((int) backupOrg[t2+m+m+2].blue);
				// truncate each pixel's color values to match the range [0,255]
				t4=t3+j;
				pixelsImg[t4].red = (unsigned char) (min(max(sum.red, 0), 255));
				pixelsImg[t4].green = (unsigned char) (min(max(sum.green, 0), 255));
				pixelsImg[t4].blue = (unsigned char) (min(max(sum.blue, 0), 255));
			}
		}

		free(backupOrg);
			
		// write result image to file
		writeBMP(image, srcImgpName, filteredSharpRsltImgName);	
	}
}

