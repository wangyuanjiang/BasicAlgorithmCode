class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;

		int n = haystack.length();
		int m = needle.length();
		int i = 0;
		int j = 0;
		auto b = make_unique<int[]>(m + 1);
		preprocess(needle, b.get());

		while (i < n) {
			while (j != -1 && haystack[i] != needle[j]) j = b[j];
			i++;
			j++;
			if (j == m) return i - j;
		}
		return -1;
	}

	void preprocess(const string& needle, int* b) {
		b[0] = -1;

		for (size_t i = 0; i < needle.length(); ++i) {
			int j = b[i]; // ����Ϊ i �� border ���Ϊ j
			while (j != -1 && needle[i] != needle[j]) j = b[j];
			b[i + 1] = j + 1;
		}
	}
};
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;

		if (haystack.length() == 0)
			return -1;

		if (needle.length() > haystack.length())
			return -1;

		size_t des = haystack.length();
		size_t s = needle.length();
		for (int i = 0; i <= des - s; i++)
		{
			if (needle[0] == haystack[i])
			{
				for (int j = 0; j < s; j++)
				{
					//  ÿ���ַ���Ҫ��Ȳ��У�ֻҪ�м��в���ȵ��ַ�����ת�������else if��breakСѭ��
					if (needle[j] == haystack[i + j] && j == (s - 1))
						return i;
					else if (needle[j] != haystack[i + j])
						break;
				}
			}
		}
		return -1;  // ��ͷ��β��û���ҵ����ϵģ���ô��Ȼ�ǲ������ˡ�
	}
};
class Solution {//�����ⷨ
public:
	int strStr(string haystack, string needle) {
		int k = 0;
		if (needle.empty())
			return 0;

		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack[i] == needle[0])
			{
				int temp = i;
				for (int j = 0; j < needle.size(); ++j)
				{
					if (haystack[temp++] != needle[j])
						break;
					else {
						if (temp - i == needle.size())
							return i;
					}
				}

			}
		}
		return -1;
	}
};