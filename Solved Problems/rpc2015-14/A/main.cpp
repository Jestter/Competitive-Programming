

#include <iostream>
#include <string>
#include <stdio.h>
int main(int argc, const char * argv[]) {
    char x[10];
    char y[10];
    char z[10];
    char op = 0;
    int loops = 0;
    scanf("%d\n", &loops);
    
    for(int i=0; i<loops; i++){
        
        scanf("%s %c %s = %s", x, &op, y ,z);
        printf("%s %c %s = %s\n", x, op, y ,z);
        bool worked_once = false;
        for (int base = 2; base <= 36; base++) {
            try{
                double x_1 = (double)std::stoi(x, nullptr, base);
                double y_1 = (double)std::stoi(y, nullptr, base);
                double z_1 = (double)std::stoi(z, nullptr, base);
                
                bool worked = false;
                switch (op) {
                    case '+':
                        if(x_1 + y_1 == z_1)
                            worked = true;
                        break;
                    case '-':
                        if(x_1 - y_1 == z_1)
                            worked = true;
                        break;
                    case '*':
                        if((x_1 * y_1) == z_1)
                            worked = true;
                        break;
                    case '/':
                        if((x_1 / y_1) == z_1)
                            worked = true;
                        break;
                    default:
                        break;
                }
                if(worked){
                    worked_once = true;
                    if(base <= 9)
                        printf("%d", base);
                    else if (base < 36){
                        printf("%c", 'a'+base-10);
                    }
                    else if (base == 36){
                        printf("0");
                    }
                }
            }
            catch(...){
                continue;
            }
        }
        
        
        if(!worked_once)
            printf("invalid");
        printf("\n");
        
    }
    return 0;
}