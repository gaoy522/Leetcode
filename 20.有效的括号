bool isValid(char * s){
    char *stack = (char *)malloc(sizeof(char) * 5000);   //给栈stack分配空间。
    int index=0,var=0;char a=*(s+index);   //*(s+index)可取得每个字符。
    while(a!='\0'){   //判断是否到达字符串末尾。
        switch (a){   //是'(','[','{'时，将字符存入stack。
            case 40:
            case 91:
            case 123:
                stack[var++]=a;
                break;
            default:  //不是'(','[','{'时，若stack中上一个位置存储的是对应括号另一半，消去stack上一位置，否则retrun false。
                if(var==0)
                    return false;
                var--;
                switch (a){
                    case 41:
                        if(stack[var]!=40){
                            return false;
                        }break;
                    case 93:
                        if(stack[var]!=91){
                            return false;
                        }break;
                    case 125:
                        if(stack[var]!=123){
                            return false;
                        }break;
                    default:
                        return false;
                }
        }
        ++index;a=*(s+index);   //取得下一个字母。
    }
    if(var==0)return true;    //如果stack里的括号全都抵消完了说明匹配成功。
    return false;    //有剩余的说明有的字符串没有被匹配。
}

// 注意：
// 1.可以用*(s+index)表示char *s中的每一个字符的值
// 2.char *stack = (char *)malloc(sizeof(char) * 5000)可改为动态分配空间，不够再分配的形式
// 3.通过while(a!='\0')判断是否已到字符串末尾 
//
//
