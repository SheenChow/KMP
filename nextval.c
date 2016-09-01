/*
*KMP模式匹配算法的实现
*通过计算返回子串T的nextval数组，是KMP算法的改进
*/
void get_nextval(String T, int* nextval) {

	int i = 1;

	int j = 0; 

	nextval[1] = 0;

	//T[0]中存储的是字符串T的长度
	while(i < T[0]) { 

		/*
		*T[i]代表后缀中的每一项
		*T[j]代表前缀中的每一项
		*/
		if (j == 0 || T[i] == T[j]) {

			++i;

			++j;

			if (T[i] != T[j]) {  //此时增加了一项比较当前字符与前缀字符是否相等的步骤

				nextval[i] = j;

			} else {

				nextval[i] = nextval[j];

			}    

		} else {
			
            /*若字符不相同，则j值回溯*/
			j = nextval[j];

		}
	}
}