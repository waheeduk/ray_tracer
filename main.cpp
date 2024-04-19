#include <iostream>
#include <fstream>

int main () {
	// Image
	
	std::ofstream image;
	image.open("image.ppm");
    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	if (image.is_open()){
		image<<"P3\n";
		image<<image_width<<"\n";
		image<<image_height<<"\n";
		image<<"255"<<"\n";
	}
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            image << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
	image.close();
	printf("Press ENTER key to Continue\n");  
	getchar();
}
