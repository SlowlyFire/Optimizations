# Optimizations  
In this project we were asked to optimize a given program in c.  
In order to optimize the given program, we used some optimizations, regardless of the processor / compiler optimizations.  
**Optimizations I used for examples**:  
  
# - **Code Motion**:  
<img src="https://user-images.githubusercontent.com/83518959/192632000-4fce43ab-baa4-4fce-b49f-0080c40e105f.png" width="450" height="300" />   
  
# - **Reduction in Strength**:  
<img src="https://user-images.githubusercontent.com/83518959/192632116-a04c3ac2-890f-4050-9b42-7871a51c81b5.png" width="450" height="300" />  
  
# - **Using more efficient instructions**:    
<img src="https://user-images.githubusercontent.com/83518959/192632243-a484d4c4-18d3-442e-827e-6adaae0b1885.png" width="450" height="300" />  
<img src="https://user-images.githubusercontent.com/83518959/192632321-70b8cd5e-14d6-40e4-9405-68ef88e5ce2a.png" width="450" height="300" />  
<img src="https://user-images.githubusercontent.com/83518959/192632421-fc9d8fe7-57a7-4f10-b67a-291c6bd1efab.png" width="450" height="300" />  
    
# - **Loop Unrolling**:  
<img src="https://user-images.githubusercontent.com/83518959/192632657-e51ad8cf-8dfb-4006-8956-87ae6d010eae.png" width="450" height="300" />  
<img src="https://user-images.githubusercontent.com/83518959/192632745-4e51ab59-48c6-4c8b-9fd9-2b10b68642b0.png" width="450" height="300" />  
  
  
  
In order to compile the project, there is a makefile, so we should write down "make" in terminal.  
then, to run the project we should write: "./showBMP <imageName> <kernelOption>", such as: ./showBMP gibson_500.bmp 1 or
./showBMP gibson_500.bmp 2 .  
  
**at first, the original program runs very slow, you can see here:**  
with filter 1:  
![image](https://user-images.githubusercontent.com/83518959/192640327-e1bd1eb3-f74e-47af-95ab-09b6ee441387.png)  
with filter 2:  
![image](https://user-images.githubusercontent.com/83518959/192640953-70c4fd11-efd8-4315-8b3a-60460c5243cc.png)  

  
**and then, the program I optimized, you could see the difference between the seconds:**   
with filter 1:  
![image](https://user-images.githubusercontent.com/83518959/192642142-fd750be3-d184-4346-b6f7-cb0d67e5b5ce.png)  
with filter 2:  
![image](https://user-images.githubusercontent.com/83518959/192642592-2cf73e6d-e57b-4436-8e09-8895681f4d4b.png)  
  
  
* we should notice that it can be any photo, the gibson is just an example.  
## the project just demonstrate the difference between a regular code, to an optimized and efficient code, where time is matter.  
