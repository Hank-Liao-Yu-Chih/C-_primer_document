# 6.1函式基礎
```c++
#include <iostream>

using namespace std;

int fact(int val)
{
	int ret = 1;
    while(val > 1)
        ret *= val--;
    return ret;
}

int main(void)
{
    int j = fact(5);
    cout << "5! is " << j << endl;
    return 0;
}
```

### 參數與引數

```c++
fact("hello");			// 錯誤:引數型別有誤
fact();					// 參數:引數太少
fact(42, 10, 0);		// 錯誤:引數太多
fact(3.14);				// ok:引數會被轉換為int等同於fact(3)
```

### 函數參數列

```c++
void f1();				// 隱含的空參數列
void f2(void);			// 明確的空參數列
int f3(int v1, v2);		// 錯誤
int f4(int v1, int v2);	// ok
```

### 自動物件(Automatic Objects)

參數是自動物件。用於參數的儲存區是在函式起始時配置的。參數式在函式主體的範疇中定義的，因此它們會在函式終結時被摧毀。

### 區域static物件

區域static物件都會在執行第一次經過物件的定義時初始化。區域性的static並不會在函式結束時摧毀，它們是在程式終結時才被摧毀。

```c++
#include <iostream>

using namespace std;

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}
int main(void)
{
    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << endl;
    return 0;
}
```

# 6.2引數傳遞

## 6.2.1藉由值傳遞引數

```c++
int n = 0;				// 型別為int的一般變數
int i = n;				// i是n中的值的一個拷貝
i = 42;					// i中的值改變了，但是n沒有變化
```

### 指標參數

```c++
int n = 0, i = 42;		// p指向n;q指向i
int *p = &n, *q = &i;	// n中的值改變了;p沒有改變
p = q;					// p現在指向i;i和n中的值不變
```

```c++
// 接受一個指標並把其所指的值設為0的函式
void reset(int *ip)
{
    *ip = 0;		// 變更ip所指的物件之值
    ip = 0;			// 只改變ip的區域性拷貝;引數沒有變化
}
```

## 6.2.2藉由參考傳遞引數

```c++
int n = 0, i = 42;
int &r = n;						// r繫結至n
r = 42;							// n現在是42
r = i;							// n現在有跟i相同的值
i = r;							// i有與n相同的值
```

```c++
void reset(int &i)
{
    i = 0;						// 改變i所指涉的物件的值
}
```

```c++
int j = 42;
reset(j);					// j的值改變了
cout << "j = " << j << endl;
```

### 使用參考來避免拷貝

```c++
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

### 使用參考參數來回傳額外資訊

```c++
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;				// 紀錄第一次出現
            ++occurs;
        }
    }
    return ret;
}
```

### const 參數與引數

```c++
const int ci = 42;			// 我們無法改變ci，這個const是頂層的
int i = ci;					// OK,當我們拷貝ci，它的頂層const會被忽略
int * const p = &i;			// error:const是頂層，我們無法指定給p(p的內容是不能更改，但是p所指的內 
                            // 容可以更改)
*p = 0;						// OK，透過p的變更是被允許的，i現在為0
```

```c++
int i = 42;
const int *cp = &i;			// ok:但cp不能更改
const int &r = i;			// ok:但是r不能更改i
const int &r2 = 42;			// ok
int *p = cp;				// 錯誤:p和cp的型別不吻合
int &r3 = r;				// 錯誤:r3和r的型別不吻合
int &r4 = 42;				// 錯誤:不能用一個字面值初始化一個普通的參考
```

### Note:盡可能使用對const的參考

## 6.2.6帶有不定參數的函式

### initializer_list參數

#### 表:initializer_list上的運算

```C++
initializer_list<T> list;				// 預設初始化；型別為T的元素所形成的一個空串列
initializer_list<T> list = {a, b, c};	// lst(a,b,c,...)	
lst2(lst);								// 拷貝或是指定一個initializer_list並不會拷貝
lst2 = lst;								// 串列中的元素與原拷貝的會共用那些元素
lst.size();								// 串列中的數目		
lst.begin();							// 回傳串列中第一個元素的地方
lst.end();								// 回傳串列中超過最後一個元素的地方
```

跟**vector**不同的是，**initializer_list**中的元素永遠都會是**const**值:

```c++
void error_msg(initializer_list<string> i1)
{
    for (auto beg = i1.begin(); beg != i1.end(); ++beg)
        cout << *beg << "	";
    cout << end;
}
```

