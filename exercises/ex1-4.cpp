#include <iostream>
#include <string>

int main() {
    
    int N[5];    

    std::cout << "Please give me 5 other numbers! " << std::endl;
    std::cin >> N[0] >> N[1] >> N[2] >> N[3] >> N[4];
    std::cout <<  std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int k = j+1;
            if (N[j] > N[k]) { 
                int temp = N[k];
                N[k] = N[j];
                N[j] = temp;
            }
        }
    }
    std::cout << "after sorting :" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << N[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}