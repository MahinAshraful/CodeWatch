#include <stdlib.h>

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/*
Drawing Lots

º}Ìæ¤È¢íÉ­¶ª èÜ·B±ÌáÅÍcüÌªT{ èAS{Ì¡üªø©êÄ¢Ü·B¡üÍcüðÜ½¢Åàæ¢ÆµÜ·B

}ÌãÅÍ 1, 2, 3, 4, 5 ÌÔÅ Á½àÌªAQÔÚÆSÔÚÌÔÅÌð·i±êð (2, 4) Ìæ¤É­jðµA³çÉA(3, 5)(1, 2)(3, 4) Ìð·ðµ½ÌÅA}ÌºÉ½Æ«ÍA4, 1, 2, 5, 3 ÉÈèÜµ½B

ÅÌóÔ@1, 2, 3, 4.... ªA^¦çê½¡_ÌXgi±ÌáÅÍA(2, 4)(3, 5)(1, 2)(3, 4) ðÊßµ½Ì¿AÇÌæ¤ÈÔÉÈé©ðoÍµÄI¹·évOðì¬µÄº³¢B
Input

cüÌ{ w (®Fw  30)
¡_Ì{ n (®Fn  30)
¡_Xg a1, b1 (®F¼pJ}æØè) ¡_Xg a2, b2 (®F¼pJ}æØè) .
.
.
¡_Xg an, bn (®F¼pJ}æØè)
Output

¶©çEÉA
1 ÔÚÌ_Éé
2 ÔÚÌ_Éé
.
.
w ÔÚÌ_Éé
Sample Input

5
4
2,4
3,5
1,2
3,4

Output for the Sample Input

4
1
2
5
3

*/

using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	string s;
	int w, n;

	getline(cin, s);
	sscanf(s.c_str(), "%ld", &w);
	getline(cin, s);
	sscanf(s.c_str(), "%ld", &n);
	
	vector<int> v;
	for (int i = 0; i < w; i++)
	{
		v.push_back(i + 1);
	}
	
	for (int i = 0; i < n; i++)
	{
		int a, b;
		getline(cin, s);
		sscanf(s.c_str(), "%ld,%ld", &a, &b);
		swap(&v[a - 1], &v[b - 1]);
	}
	
	for (int i = 0; i < w; i++)
	{
		printf("%d\n", v[i]);
	}

	return 0;
}