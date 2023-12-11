/*#include<iostream>
using namespace std;
int main(){
//    string a;
//    cin>>a;
//    for(int i=0;i<a.size();i++){
//        if (a[i]>'a'&&a[i]<'z')
//            a[i]=a[i]-32;
//    }
//    cout<<a<<endl;
//}
int main(){
    int n,m;
    cin>>n;
    n=n%26;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        m=s[i]+n;
        if(m>'z'){
            s[i]=(m-122)%26+96;
        }
        else{
            s[i]=m;
        }
    }
    cout<<s<<endl;
}
#include <iostream>
using namespace std;
int a[105];
int main() {
    int i = 0;
    while (1) {
        cin >> a[i];
        if (a[i] == 0) {
            break;
        }
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }tre
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main (){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,count=0,flag=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if (s[i]=='V'&&s[i+1]=='K'){
            count+=1;
            s[i]=s[i+1]='A';
        }
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='V'&&s[i+1]=='V'){
            flag=1;
        }
        if(s[i]=='K'&&s[i+1]=='K'){
            flag=1;
        }
    }
    if (flag){
        count+=1;
    }
    cout<<count;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[23][23]={0};
int main (){
    int n;
    cin>>n;
    a[0][1]=1,a[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            a[i][j]=a[i-1][j]+a[i-1][j-1];
            cout<<a[i][j]<<' ';
        }
        cout<<' '<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[1001][7]={0};
int main (){
    int n,num;
    int b[7]={0};
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<7;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        num=0;
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                if(a[0][k]==a[i][j]){
                    num+=1;
                }
            }
        }
        b[7-num]+=1;
    }
    for(int i=0;i<7;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,num=0;
        int a[50005]={0};
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>m;
            bool present=std::find(a,a+num,m)!=a+num;
            if (present==false){
                a[i]=m;
                num++;
                printf("%d",m);
                if(i==n-1)cout<<'\n';
                else cout<<' ';
            }
        }
    }
    return 0;
}

*/
/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=1e6+5;
ll a[p];
int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(m--){
        ll num,flag=0,low=1,hei=n;
        ll mid=(hei+low)/2;
        cin>>num;
        while(hei-low>10){
            if(a[mid]>=num) hei=mid;
            else low=mid;
        }
        int i;
        for(i=low;i<=hei;i++){
            if(a[i]==num){
                flag=1;
                break;
            }
        }
        if(flag)cout<<i<<' ';
        else cout<<-1<<' ';
    }
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e6+5;
ll a[p], n,m;
ll find(ll num){
    ll hei=n,low=1;
    while(hei>low)
    {
        ll mid=low +(hei-low)/2;
        if(a[mid]>=num) hei=mid;
        else low=mid+1;
    }
    if(a[low]==num)return low;
    else return -1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        ll num,flag;
        cin>>num;
        flag=find(num);
        cout<<flag<<' ';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;//
int a[100005];
void bubble_sort(int *a, int n) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        flag = true;
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
    }
  }
}
int main(){
    int n,m,num,sum=0,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
       cin>>a[i];
    }
    bubble_sort(a,n);
    for(int i=1;i<=m;i++){
        cin>>num;
        int hei=n,low=1;
        while(hei-low>3){
            int mid=(hei+low)/2;
            if(a[mid]>num)hei=mid;
            else low=mid;
        }
        sum=abs(a[low]-num);
        for(int j=low+1;j<=hei;j++)
            sum=min(abs(a[j]-num),sum);
        ans+=sum;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;//
int a[100005];
void bubble_sort(int *a, int n) //冒泡排序
{
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        flag = true;
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
    }
  }
}
int main(){
    int n,m,num,*p,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
       cin>>a[i];
    }
    bubble_sort(a,n);//将数组排序
    for(int i=1;i<=m;i++){
        cin>>num;
        p=std::lower_bound(a+1,a+n,num);
        if(*(p-1)==0)ans=ans+min(*(p)-num,*(p+1)-num);//判断是否是a[1]的地址
        else ans=ans+min(abs(*(p-1)-num),abs(*p-num));//不是a[1]则执行这个
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005];
set<int>b;
int main(){
    int n,m,num,ans,*p;
    cin>>n>>m;;
    for(int i=1;i<=n;i++) {
       cin>>a[i];
       b.insert(a[i]);
    }
    set<int>::iterator it = b.begin();
    for(int i=1;i<=b.size();i++){//借助集合来排序数组
      a[i]=*it;
      it++;
    }
    for(int i=1;i<=m;i++){
      cin>>num;
      p=std::lower_bound(a+1,a+n,num);
      if(p-1==a)ans=ans+min(*(p)-num,*(p+1)-num);//判断是否是a[1]的地址
      else ans=ans+min(abs(*(p-1)-num),abs(*p-num));//不是a[1]则执行这个
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,m,num,ans,*p;
    cin>>n>>m;;
    for(int i=1;i<=n;i++) {
       cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
      cin>>num;
      p=std::lower_bound(a+1,a+n,num);
      if(p-1==a)ans=ans+min(*(p)-num,*(p+1)-num);//判断是否是a[1]的地址
      else ans=ans+min(abs(*(p-1)-num),abs(*p-num));//不是a[1]则执行这个
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  double s,b,a;
  cin>>s>>a>>b;
  double t1,t2,t;
  t1=s*(a+b)/(b*b+3*a*b);
  t2=(t1*2*b-s)/b;
  t=2*t1+t2;
  cout<<t1*b<<endl;
  cout<<t2<<endl;
  cout<<fixed<<setprecision(6)<<t;
}



#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  cin>>n>>p;
  vector <int>a(n+1),b(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i]-a[i-1];
  }
  while(p--){
    int x,y,z;
    cin>>x>>y>>z;
    b[x]+=z;
    b[y+1]-=z;
  }
  for(int i=1;i<=n;i++){
    a[i]=b[i]+a[i-1];
  }
  sort(a.begin()+1,a.end());
  cout<<a[1];
  return 0;
}

#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int fa[maxn];
int find(int x) // 找到根
{
  return fa[x] == x ? x : fa[x] = find(fa[x]);
} // 判断是否为根       若不是，继续往上找
void merge(int x, int y) // 将数集合并
{
  fa[find(x)] = find(y);
} // 左边为y的根位置，右边为x的根位置，将x根的位置传给y的根位置
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  while (m--)
  {
    int z, x, y;
    cin >> z >> x >> y;
    if (z == 1)
      merge(x, y);
    else
    {
      if (find(x) == find(y))
        cout << 'Y' << endl;
      else
        cout << 'N' << endl;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << fa[i] << ' ';
  return 0;
}

#include<iostream>
using namespace std;
int a[100005],pre[100005];
int main(){
  int n,m;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    pre[i]=a[i]+pre[i-1];
  }
  cin>>m;
  while(m--){
    int h,l,ans;
    cin>>l>>h;
    ans=pre[h]-pre[l-1];
    cout<<ans<<endl;
  }
  return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], pre[maxn];
int main()
{
  int n, sum = 0, ans = -2147483647;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (i == 1)
      pre[i] = a[i];
    else
      pre[i] = max(a[i], pre[i - 1] + a[i]);
    ans = max(pre[i], ans);
  }
  cout << ans;
  return 0;
}

#include <iostream>
#define ll long long
using namespace std;
ll a[200005], b[200005];
int main()
{
  ll n, s = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    b[i] = a[i] + b[i - 1];
  }
  for (int i = 1; i <= n; i++)
  {
    s = s + (b[n] - b[i]) * a[i];
  }
  cout << s;
  return 0;
}

#include <iostream>
using namespace std;
// 设置好月份对应的天数
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 判断是否闰年，是则返回1，否则返回零
int juage(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
  {
    return 1;
  }
  else
    return 0;
}
int main()
{
  int year, mon;
  cin >> year >> mon;
  if (mon != 2) // 月份不是2，则正常输出
    cout << a[mon - 1];
  else // 若是2，则先判断是否为闰年，再输出
  {
    if (juage(year))
      cout << a[mon - 1] + 1;
    else
      cout << a[mon - 1];
    return 0;
  }
}

#include <iostream>
using namespace std;
int main()
{
  int n, m = 3, sum, ans;
  cin >> n;
  for (int i = 0; i < m; i++)
  {
    int pri, num;
    cin >> num >> pri; // 输入价格与数量
    if (n % num == 0)  // 判断该方案与所需数量的关系
      sum = n / num;
    else
      sum = n / num + 1;
    if (i == 0) // 如果是第一次计算方案，直接赋给ans
      ans = sum * pri;
    else // 若不是，与上一次进行比较，取最小值
      ans = min(ans, sum * pri);
  }
  cout << ans;
  return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int p[3], a, b, c, l;
  for (int i = 0; i < 3; i++)
  {
    cin >> p[i];
  }
  sort(p, p + 3); // 对输入的数进行排序，最小赋值给a，最大给c
  a = p[0], b = p[1], c = p[2];
  if (a + b > c && a + c > b && b + c > a)
  { // 判断是否能够构成三角形，且是怎样的三角形
    if (a * a + b * b == c * c)
      cout << "Right triangle\n";
    if (a * a + b * b > c * c)
      cout << "Acute triangle\n";
    if (a * a + b * b < c * c)
      cout << "Obtuse triangle\n";
    if (a == b || a == c || b == c)
      cout << "Isosceles triangle\n";
    if (a == b && a == c)
      cout << "Equilateral triangle\n";
  }
  else
    cout << "Not triangle\n";
  return 0;
}

#include <iostream>
#include <iomanip>
#define pri1 0.4463 // 首先将三个价格提前定义，后面更简便
#define pri2 0.4663
#define pri3 0.5663
using namespace std;
int main()
{
  float n, sum;
  cin >> n;
  // 判断电量多少
  if (n <= 150)
    sum = n * pri1;
  else if (n > 150 && n <= 400)
    sum = 150 * pri1 + (n - 150) * pri2;
  else
    sum = 150 * pri1 + 250 * pri2 + (n - 400) * pri3;
  printf("%.1f", sum); // 注意控制精度
  return 0;
}

#include <iostream>
using namespace std;
#define step 250
int main()
{
  int x, n;
  cin >> x >> n;
  int sum, a, day = 0, b;
  a = 7 - x + 1; // 计算这一周剩下几天
  if (x < 6)     // 判断是否为工作日
    day = a - 2;
  b = (n - a) % 7; // 判断最后一周在星期几结束,0为周七
  if (b < 6 && b != 0)
    day = day + b;
  else if (b == 6)
    day = day + 5; // 如果周6结束，直接加上前五天
  sum = (day + (n - a - b) / 7 * 5) * step;
  cout << sum;
  return 0;
}

#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main()
{
    int n, ans = -0x3f3f3f3f;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (n == 1)
            b[i] = a[i];
        else
            b[i] = max(a[i], b[i - 1] + a[i]);
    }
}


#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[5], b[5];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'A')
            cout << a[0] << ' ';
        else if (s[i] == 'B')
            cout << a[1] << ' ';
        else if (s[i] == 'C')
            cout << a[2] << ' ';
    }
    return 0;
}



#include <iostream>
using namespace std;

#define ll long long
const ll p = 1e6 + 5;
ll a[p];
int main()
{
  ll n, m, tar;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (m--)
  {
    ll low = 1, hei = n, mid, ans = -1;
    cin >> tar;
    mid = (hei + low) / 2;
    while (abs(a[mid] - tar) > 3)
    {
      if (a[mid] > tar)
        hei = mid;
      else
        low = mid - 2;
      mid = (hei + low) / 2;
    }
    for (ll i = low; i <= hei; i++)
    {
      if (a[i] == tar)
      {
        ans = i * 2;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}




*/
#include <iostream>
using namespace std;

#define ll long long
const ll p = 1e6 + 5;

ll a[p];

int main()
{
  ll n, m, target;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (m--)
  {
    ll low = 1, hei = n, mid, ans = -1;
    cin >> target;
    while (low <= hei)
    {
      mid = (low + hei) / 2;
      if (abs(a[mid] - target) <= 3)
      {
        for (ll i = max(1ll, mid - 3); i <= min(n, mid + 3); i++)
        {
          if (a[i] == target)
          {
            ans = i * 2;
            break;
          }
        }
        break;
      }
      else if (a[mid] > target)
        hei = mid - 1;
      else
        low = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}