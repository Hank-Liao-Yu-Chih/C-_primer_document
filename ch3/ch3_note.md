# 3.1命名空間的宣告

一個**using**宣告讓我們可以使用一個命名空間中的名稱，而不用以**namespace_name::**前綴來對名稱進行資格修飾

```c++
using namespace::name
```

```c++
#include <iostream>
// using宣告，當我們使用cin這個名稱，我們就會對取得來自命名空間std的那一個
using std::cin;
int main()
{
    int i;
    cin >> i;			// ok, cin是std::cin的同義字
    cout << i;			// 錯誤:沒有使用using宣告，我們必須使用全名
    std::cout << i;		// ok:明確使用來自命名空間std的cout
    return 0;
}
```

## 每個名稱都需要一個分別的using宣告

```c++
#include <iostream>

using std::cin;
using std::cout; using std::endl;
int main()
{
    cout << "Enter two numbers:" << endl;
    int v1, v2;
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and" << v2
         << " is " << v1 + v2 << endl;
    return 0;
}
```

or 

```c++
#include <iostream>

using namepace::std;
int main()
{
    cout << "Enter two numbers:" << endl;
    int v1, v2;
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and" << v2
         << " is " << v1 + v2 << endl;
    return 0;
}
```

## 標頭(Header)不應該包含using宣告

# 3.2程式庫的string型別

## 3.2.1定義並初始化string

```c++
#include <iostream>
#include <string>
using std::string;
int main()
{
    string s1;						// 預設初始化，s1是空字串(empty string)
    string s2 = s1;					// s2是s1的一個拷貝
    string s3 = "hiya";				// s3是字串字面值("hiya")的一個拷貝
    string s4(10, 'c');				// s4是cccccccccc
    string s5 = "hiya";				// copy initialization
    string s6("hiya");				// direct initialization
    string s7(10, 'c');				// direct initialization s7是cccccccccc
    string s8 = string(10, 'c');	// copy initialization s8是cccccccccc
    return 0;
}
```

## 3.2.2在string上進行運算

### 讀取和寫入string

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string s;			// 空字串
    cin >> s;			// 讀入一個由空白分隔的字串到s中
    cout << s << endl;	// 將s寫到輸出
    return 0;
}
```

### 讀取未知數目的string

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string word;
    while (cin >> word)			// 一直讀到檔案結尾(end-of-file)
        cout << word << endl;	// 寫出每一個字，後面接著一個newline
    return 0;
}
```

PS:以上的寫法會忽略空白

### 使用getline來讀取一整行

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string line;
    // 讀取輸入，一次讀一行，直到檔案結尾為止
    while (getline(cin, line))
        cout << line << endl;
    return 0;
}
```

PS:以上寫法會保留空白

### string的empty和size運算

**empty**:它會回一個**bool**，指出string是否為空的(**empty**)

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string line;
    // 讀取輸入，一次讀一行，並捨棄空白文字行
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return 0;
}
```

**size**成員回傳一個**string**的長度(即其中的所含的字元數)

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string line;
    // 讀取輸入，一次讀一行，並印出大於80的字元長度的文字行
    while (getline(cin, line))
        if (line.size() > 80)
            cout << line << endl;
    return 0;
}
```

### string::size_type型別

**size**回傳的為無號型別，通常的用法如下:

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string line;
    auto len = line.size() // len有型別string::size_type
    return 0;
}
```

#### Tip: 你可以避免因為unsigned和int之間的轉換而產生的問題，只要不要在用到size()的運算式中使用int就可以了

### 比較string

1. 如果兩個string有不同的長度，而且較短的string中的每個字元都等於較長string中對應的字元，那麼較短的string就小於較長的

2. 如果兩個string中對應位置上的任何字元有不同，那麼字串比較的結果就是比較字串不同處的第一字元

3. ```c++
   string str = "Hello";
   string phrase = "Hello World"
   string slang = "Hiya!"
   ```

### string的指定

```c++
string st1(10, 'c'), st2; 	// st1是cccccccccc，st2是空字串
st1 = st2;					// 指定:以st2的一個拷貝取代st1的內容
							// 現在st1及st2都是空字串
```

### string的相加

```c++
string s1 = "hello", s2 = "world\n";
string s3 = s1 + s2;					// s3是hello, world\n
s1 += s2;								// 等同於s1 = s1 + s2
```

```c++
// 每一個+運算子至少要有一個運算元是string
string s1 = "hello", s2 = "world";			//s1和s2中都沒有標點符號
string s3 = s1 + ", " + s2 + '\n';
string s4 = s1 + ",";						// ok,相加一個string和一個字串值
string s5 = "hello" + ", ";					// 錯誤:沒有string運算元
string s6 = s1 + ", " + "world";			// ok, 每個+都有一個string運算元
string s7 = "hello" + ", " + s2;			// 錯誤:不能相加字串字面值
```

## 3.2.3處理一個string中的字元

### 要處理每個字元?哪就用基於範圍的for

```c++
for (declaration : experession)
    statement
```

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string str("some string");
    for (auto c : str)
        cout << c << endl;
    return 0;
}
```

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string str("Hello World!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
   
    return 0;
}
```

### 使用一個範圍for來變更一個string中的字元

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string s("Hello world");
    // 將s轉成大寫
    for (auto &c : s) // 對s中的每個char(注意:c是一個參考)
        c = toupper(c); // c是一個參考，所以指定會改變s中的char
    cout << s << endl;
   
    return 0;
}
```

### 使用index來存取string中的字元

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string s("some string");
   
    // 將s[0]改成大寫
    if (!s.empty())
        cout << s[0] << endl;
    
    if (!s.empty())
        s[0] = toupper(s[0]);
   
    cout << s << endl;
    return 0;
}
```

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    string s("some string");
   
    if (s.empty())
        return -1;
    
    // 利用index把S的字元變大寫，遇到空白就結束
    for (decltype(s.size()) index = 0;
         index != s.size() && !isspace(s[index]); ++index)
        	s[index] = toupper(s[index]);
   
    cout << s << endl;
    return 0;
}
```

```c++
#include <iostream>
#include <string>
using namespcae::std;
int main()
{
    const string hexdigits = "0123456789ABCDEF"
    
    string result;
    string::size_type n;
    while (cin >> n)
         // 利用string::size_type n，來判斷是否有超出範圍
        if (n < hexdigits.size())
            result += hexdigits[n];
    cout << "Your hex number is:" << result << endl;

    return 0;
}
```

## 3.3程式庫的vector型別

#### Note:vector是一個模板，而非一個型別。從vector產生的型別必須包含元素型別，例如vector<int>

### 3.3.1定義並初始化vector

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
	vector<int> ivec;				// 一開始是空
    vector<int> ivec2(ivec);		// 將ivec的元素拷貝到ivec2
    vector<int> ivec3 = ivec;		// 將ivec的元素拷貝到ivec2
    vetcor<string> svec(ivec2);		// 錯誤:sevc存有的是string，而非int
    return 0;
}
```

#### vector的串列初始化/創建特定數目的元素/值初始化

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
    vector<string> v1{"a", "an", "the"}; 	// 串列初始化
    vetcor<string> v2("a", "an", "the"); 	// 錯誤 (不能用括號)
    vector<int> ivec(10,-1);				// 10個int元素，每個都被初始化為-1
    vector<string> svec(10, "hi");			// 10個string，每個元素都是"hi"
    vector<int> ivec(10);					// 10個int元素，每個都被初始化為0
    vector<string> svec(10, "hi");			// 10個string元素，每個都是"hi"
    return 0;
}
```

#### 串列出初始器還是元素計數器

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
	vector<int> v1(10);			// v1有10個值為0的元素
    vector<int> v2(10);			// v2有1個值為10的元素
    vector<int> v3(10, 1);		// v3有10個值為1的元素
    vector<int> v4{10, 1};		// v4有2個值分別為10與1的元素
    vector<string> v5{"hi"};	// 串列初始化:v5有一個元素
    vector<string> v6("hi");	// 錯誤:無法以一個字串字面值建構一個vector
    vector<string> v7{10};		// v7有10個預設初始化的元素
    vector<string> v8{10, "hi"};// v8有10個值為"hi"的元素	

    return 0;
}
```

### 3.3.2新增元素到一個vector

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
	vector<int> v2;	//空的vector
    for (int i = 0; i != 100; ++i)
        v2.push_back(i); //將循序的整數附加到v2
    return 0;
}
```

#### 關鍵概念:vector能夠有效率地增長:

##### 因為vector能夠有效率地增長，定義特定大小的vector經常是不必要，也會導致不好的效能

#### WARNING:一個範圍for的主體必不能改變它所迭代的序列大小

### 3.3.3其他的vector運算

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
	vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i : v)
        i *= i;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
```

#### Note:vector要使用size_type，我們必須指出它是哪個型別中所定義的。

```c++
vector<int>::size_type // ok
vector::size_type // 錯誤，沒有明確指定型別
```

#### vector的運算

```c++
v.empty();			// 如果v是空的，救回傳true:否則就回傳false
v.size();			// 回傳v中的元素數目
v.push_back(t);		// 將帶有值v的一個元素加到v的尾端
v[n];				// 回傳v中處於位置n的元素的一個參考
v1 = v2;			// 以v2中的元素之拷貝取代v1中的元素
v1 = {a, b, c};		// 以逗號分隔的串列中的元素之拷貝取代v1的元素		
v1 == v2;			// 如果它們有相同的元素數目且每一個元素都是相等，則v1與v2相等
v1 != v2;
```

#### 計算一個vector的索引

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
	vector<unsigned> scores(11, 0);
    unsigned grade;
    while(cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10]; //為目前的欉集遞增計數器
    }
    return 0;
}
```

#### 下標並不會增加元素

不好的寫法:

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
    vector<int> ivec;		// 空的vector
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        ivec[ix] = ix;	// 災難:ivec沒有元素
    return 0;
}
```

好的寫法:

```c++
#include <iostream>
#include <vector>
using namespcae::std;
int main()
{
    vector<int> ivec;		// 空的vector
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        ivec.push_back(ix); // ok:新增了一個值為ix的元素
    return 0;
}
```

#### 注意:下標運算只會擷取已知存在的元素

```c++
vector<int> ivec;			// 空的 vector
cout << ivec[0];			// 錯誤:ivec沒有元素

vector<int> ivec2(10)		// 帶有10個元素的vector
cout << ivec2[10];			// 錯誤:ivec2有元素0,...,9
```

