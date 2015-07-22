#ifndef MYATOI
#define MYATOI
int myAtoi(char* str) {
    if (0==str) return 0;
    int result=0;
    int i=0;
    int sign = 1;
    int acceptSign=1;
    int overflow = 0;
    int acceptBlank=1;
    while (str[i]){
        if (acceptBlank){
            if (str[i]==' ' || str[i]=='\t'||str[i]=='\r'||str[i]=='\n'){
                i ++;
                continue;
            }
        }
        if (acceptSign ) {
            if (str[i]=='-'){
                sign = -1;
                acceptSign = 0;
                acceptBlank = 0;
                i++;
                printf("sign is minus\n");
                continue;
            } else if (str[i]== '+'){
                sign = 1;
                acceptSign = 0;
                acceptBlank = 0;
                i++;
                continue;
            }

        }


        if (str[i] < 0x30 || str[i] > 0x39 ){

            break;

        }

        acceptBlank = 0;

        int digit= (str[i] - 0x30);

        printf("result=%d\n",result);
        if (  (result >=214748364  ) ){
            if (result >=214748365){
                overflow = 1;
                break;
            } else if (digit > 7){
                overflow = 1;
                break;
            }
        }


            result = result * 10 + digit;

        if (result <0 ){
            overflow =1;
            printf("overflow happened here=%d\n",result);
            break;
        }
        printf("result2=%d\n",result);

        i++;
    }

    if (overflow){
        if (sign==1){
            return 2147483647;
        } else {
            return 2147483648;
        }
    }




    return result * sign;
}

void testMyAToI(){
    int result=myAtoi("2147483647");
    printf("finalresult=%d\n",result);
}

#endif // MYATOI

