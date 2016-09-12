/*返回子串T在主串S中第pos字符之后的位置，若不存在，则返回0*/

/*注:T[0]存储的是字符串T的长度*/

/*T非空，且1 <= pos <= StrLength(S)*/
int Index_KMP(String S, String T, int pos) {

	/*i用于表示主串S当前位置的下标，若pos不为1，则从pos位置开始匹配*/
	int i = pos;

	/*j用于表示子串当前位置的下标*/
	int j = 1;
    
    /*定义next数组*/
	int next[255];

	/*对子串T做分析，得到next数组*/
	get_next(T, next);

	while(i <= S[0] && j <= T[0]) {

        /*较之于BruteForce算法，增加了j == 0判断*/
		if (j == 0 || S[i] == T[j]) {
			
			++i;

			++j;

		} else {  /*指针后退，开始重新匹配*/

            /*j回溯到合适的位置，而i值不变，这就是相对于BruteForce算法做出的改进部分，不再做无意义的回溯*/
			j = next[j];

		}
	}

	if(j > T[0]) {

		return i - T[0];

	} else {

		return 0;

	}
}

因为求next数组的时间复杂度为O(m),而while循环的复杂度为O(n),所以KMP匹配算法的时间复杂度为O(m + n)
