#采用kmp算法

int strStr(char * haystack, char * needle){
    if(needle[0]=='\0')return 0;  //排除needle为空情况
    if(haystack[0]=='\0')return -1;  //排除haystack为空情况
    int len=0;
    for(int n=0;needle[n]!='\0';++n)++len;  //计算needle长度
    int Stacklen=0;
    for(int n=0;haystack[n]!='\0';++n)++Stacklen;  //计算haystack长度
    int next[len];
    next[0]=-1;
    int i=0;int j=-1;
    while(i<len-1){  //给next数组赋值，next为跳转表，例：next[10]=5,即跳转到第5个位置
        if(j==-1||needle[i]==needle[j]){
            ++i;++j;
            if(needle[i]!=needle[j]){
                next[i]=j;
            }
            else{
                next[i]=next[j];
            }
        }else{
            j=next[j];
        }
    }

    int p=0,q=0;
    while(p!=Stacklen&&q!=len){  
        if(q==-1||haystack[p]==needle[q]){  //p往后推的两种情况
            ++p;++q;
        }else{  //q跳转
            q=next[q];
        }
    }
    if (q==len)return p-len;  //以q是否到达needle末端，判断是否存在对应值
    return -1;
}
