/*
*KMP模式匹配算法的实现
*通过计算返回子串T的next数组
*/
void get_next(String T, int* next){

	int i = 1;

	int j = 0; 

	next[1] = 0;

	//T[0]中存储的是字符串T的长度
	while(i < T[0]){ 

		/*
		*T[i]代表后缀中的每一项
		*T[j]代表前缀中的每一项
		*/
		if(j == 0 || T[i] == T[j]){

			++i;

			++j;
		
		    next[i] = j;

		} else {
			
            /*若字符不相同，则j至回溯*/
			j = next[j];

		}
	}
}

注：时间复杂度是O(m)