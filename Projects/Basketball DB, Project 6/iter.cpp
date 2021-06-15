#include <iostream>
#include <set>

int main()
{
  //declare a multiset for integers
  std::multiset<int> ms;
  //an iterator that will point to the first element in ms not less than a given value
  std::multiset<int>::iterator itlb;

  //add entries to the multiset: 10 20 30 40 50 60 70
  for (int i = 1; i < 8; i++)
    ms.insert(i * 10);

  std::cout << "Elements in ms:";
  for (std::multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it)
    std::cout << " " << *it;
  std::cout << std::endl;

  //iterator that points to first element in multiset not less than 25 (so 30)
  itlb = ms.lower_bound(25);
  std::cout << *itlb << std::endl;

  std::cout << "Elements in ms less than 25:";
  // for (std::multiset<int>::iterator it = ms.begin(); it != itlb; ++it)
  for (std::multiset<int>::iterator it = itlb; it != ms.end(); ++it)
    std::cout << " " << *it;
  std::cout << std::endl;

  return 0;
}
