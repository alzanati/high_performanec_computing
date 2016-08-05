Description:
In this small project i will apply the following basic image processing algorithms
with opencl kernels :

1- histogram.
2- convolution.
3- sobel filter.

The final application will contain a basic gui implemented in qt
also i will focus more in c++11 features and some optimization on it,
under the oop paradagim.

------------------------------------------------------------------------------------
1- Requirements:
 
* Implement a parallelized alogrithms runs on nvidia gpu.


2- Designing and tooling:

* use opencl api with wrapper c++11, use cmake to manage enviroment,
  last thing is developing GUI to add more features.


3- Implementations:

* read images with different formates by c++ api.
* start by understanding c++11 wrapper.
* create a project structure with cmake.
* understand algorithms and how to parallelized it.
* write opencl kernels.
* create basic gui.
* create interface between gui and algorithms implementations.
* finish gui.


4- Testing:

* Test performance with benchmarking opencl kernels,
  also try different images and calculate SNR.


5- Fix bugs and documentations:

* use deoxygen to document classes.


6- Deploying and acknowledgement:

* open source project at github.
------------------------------------------------------------------------------------

