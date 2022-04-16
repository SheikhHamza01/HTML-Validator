#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

int main()
{
	ifstream f_html, f_tags;
	string code_html, check_tags;
	stack<string> obj;
	bool flag = 0;
	f_html.open("D:\\3rd Semester\\DSA Theory\\2020CS678\\abc.html");
	if (!f_html.is_open())
	{
		cout << "Can't open html file.\n";
		exit(1);
	}
	else
	{
		while (!f_html.eof())
		{
			f_tags.open("Tags.txt");
			if (f_tags.is_open())
			{
				f_html >> code_html;
				int length = code_html.length();
				char arr[10] = { };
				for (int i = 0; i < length; i++)
				{
					arr[i] = code_html[i];
				}
				if (*arr == '<')
				{
					while (!f_tags.eof())
					{
						flag = 0;
						f_tags >> check_tags;
						if (code_html == check_tags)
						{
							flag = 1;
							if (*(arr + 1) == '/')
							{
								if (obj.empty())
								{
									cout << "The code is not valid.\n";
									exit(1);
								}
								obj.pop();
								goto label;
							}
							obj.push(code_html);
							goto label;
						}
					}
					if (flag == 0)
					{
						cout << code_html << " Tag is not valid. So,code is not valid." << endl;
						exit(1);
					}
				}
			}
			else
			{
				cout << "Can't open txt file.\n";
				exit(1);
			}
			
		label:
			f_tags.close();
		}
	}
	if (!obj.empty())
	{
		cout << "Every opening tag don't has a closing tag that's why code is not valid.\n";
	}
	else
	{
		cout << "Code is valid because every opening tag has it's closing and each tag is valid.\n";
	}
	return 0;
}