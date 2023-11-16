#include <fstream>
#include <iostream>
using namespace std;
bool prim(int x);
int main()
{
  int x, p, cx, pmax=0;
	ifstream fin("BAC.TXT");
  while (fin >> x)
  {
    if (prim(x)) p = 0;
    else
    {
      cx = x;
      do { x = x%2 ? x+2 : x+1; } while (!prim(x));
      p = x-cx;
    }
    if (p+1 > pmax) pmax = p+1;
  }
	fin.close();
  cout << pmax;
	return 0;
}
bool prim(int x)
{
  if (x == 1) return 0;
  if (x == 2) return 1;
  if (x%2 == 0) return 0;
  for (int i = 3; i*i <= x; i += 2)
    if (x%i == 0) return 0;
  return 1;
}
