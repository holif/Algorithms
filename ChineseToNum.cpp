#include <string>
#include <iostream>

using namespace std;

const int CHN_CHAR_LENGTH = 2;
const char *chnNumChar[10] = { "零", "一", "二", "三", "四", "五", "六", "七", "八", "九" };

typedef struct {
	const char *name; //中文权位名称
	int value; //10的倍数值
	bool secUnit; //是否是节权位
} CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[] = {
	{ "十", 10, false }, { "百", 100, false }, { "千", 1000, false },
	{ "万", 10000, true }, { "亿", 100000000, true }
};

int ChineseToValue(const string& chnStr) {
	for(int val = 0; val < sizeof(chnNumChar) / sizeof(chnNumChar[0]); val++) {
		if(chnStr.compare(chnNumChar[val]) == 0) {
			return val;
		}
	}
	return -1;
}

int ChineseToUnit(const string& chnStr, bool& secUnit) {
	for(int unit = 0; unit < sizeof(chnValuePair) / sizeof(chnValuePair[0]); unit++) {
		if(chnStr.compare(chnValuePair[unit].name) == 0) {
			secUnit = chnValuePair[unit].secUnit;
			return chnValuePair[unit].value;
		}
	}
	return 1;
}

unsigned int ChineseToNumber(const string& chnString) {
	unsigned int rtn = 0;
	unsigned int section = 0;
	int number = 0;
	bool secUnit = false;
	string::size_type pos = 0;

	while(pos < chnString.length()) {
		int num = ChineseToValue(chnString.substr(pos, CHN_CHAR_LENGTH));
		if(num >= 0) {
			number = num;
			pos += CHN_CHAR_LENGTH;
			if(pos >= chnString.length()) {
				section += number;
				rtn += section;
				break;
			}
		} else {
			int unit = ChineseToUnit(chnString.substr(pos, CHN_CHAR_LENGTH), secUnit);
			if(secUnit) { //是节权位说明一个节已经结束
				section = (section + number) * unit;
				rtn += section;
				section = 0;
			} else {
				section += (number * unit);
			}
			number = 0;
			pos += CHN_CHAR_LENGTH;
			if(pos >= chnString.length()) {
				rtn += section;
				break;
			}
		}
	}
	return rtn;
}

int main(int argc, char* argv[]) {

	int num = ChineseToNumber("一百零一万");
	cout<<num;

	return 0;
}