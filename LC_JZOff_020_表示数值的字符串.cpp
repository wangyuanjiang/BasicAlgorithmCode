#include "JZOff.h"


//ע�� ��ֵ��ǰ��ͺ��涼�����пո��м䲻���У� .1Ҳ����ֵ�� 1.Ҳ����ֵ
class Solution {
public:
	bool isNumber(string s) {

		int len = s.size();

		if (len == 0)    return false;

		int point = 0, num = 0, nume = 0, i = 0;

		while (s[i] == ' ' && i < len) {	//����ǰ�˵Ŀո�
			i++;
		}
		if (i > len - 1)    return false;	//�����ǰ�濪ʼȫ�ǿո�
		while (s[len - 1] == ' ')	//������˵Ŀո�
			len--;

		if (len == 0)   return false;	//����Ӻ��濪ʼҲȫ�ǿո�

		if (s[i] == '+' || s[i] == '-')
			i++;

		if (i > len - 1)    return false;



		while (i < len)
		{
			if (s[i] >= '0'  && s[i] <= '9')
			{
				i++;
				num = 1;
			}

			else if (s[i] == '.') {
				if (point == 1 || nume == 1)   return false;

				i++;
				point = 1;
				if (num == 0 && i > len - 1)   return false;	//ֻ�е�����
			}

			else if (s[i] == 'E' || s[i] == 'e')
			{
				if (nume == 1 || num == 0)    return false;	//�ж��e����e֮ǰû�����ֵ����

				i++;
				nume = 1;
				if (i < len && (s[i] == '+' || s[i] == '-'))	//e֮�������+ -��
					i++;

				if (i > len - 1) return false;	//e֮��û�����ֵ����
			}
			/*else if (s[i] == ' ')
			{
				i++;

				if (i < len  && s[i] != ' ')
					return false;
			}*/
			else {
				return false;
			}
		}
		return true;


	}
};