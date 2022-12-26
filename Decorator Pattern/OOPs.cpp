#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// usig namespace __gnu_pbds;
using namespace std;
#define ll       long long int
#define ld              long double
#define pb              push_back
#define P               pair<int,int>
#define F               first
#define S               second
#define inf             3e18
#define vi              vector<int>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MAXN            4e5+2
// ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
// ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
// ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

// //1.DP se soch
// //2.DP se soch
// //3.DP se soch
// //graph, gcd, BS, seive
// //if NOTA,then
// //brute force hi optimal h
// class beverage{
// public:
// 	virtual int cost()=0;
	
// };
// class espresso:public beverage{
// public:
// 	int cost()
// 	{
// 		return 1;
// 	}
// };
// class addflavour:public beverage{
//  public:
//  virtual int cost()=0;	
// };
// class caramel:public addflavour{
// 	beverage Beverage;
// public:
// 	void caramel(beverage b)
// 	{
// 		Beverage=b;
// 	}
// 	int cost()
// 	{
// 		return Beverage.cost()+2;
// 	}
	
// };
class Component {
 public:
  virtual ~Component() {}
  virtual int Operation() const = 0;
};
/**
 * Concrete Components provide default implementations of the operations. There
 * might be several variations of these classes.
 */
class ConcreteComponent : public Component {
 public:
  int Operation() const override {
    return 1;
  }
};
/**
 * The base Decorator class follows the same interface as the other components.
 * The primary purpose of this class is to define the wrapping interface for all
 * concrete decorators. The default implementation of the wrapping code might
 * include a field for storing a wrapped component and the means to initialize
 * it.
 */
class Decorator : public Component {
  /**
   * @var Component
   */
 protected:
  Component* component_;

 public:
  Decorator(Component* component) : component_(component) {
  }
  /**
   * The Decorator delegates all work to the wrapped component.
   */
  int Operation() const override {
    return this->component_->Operation();
  }
};
/**
 * Concrete Decorators call the wrapped object and alter its result in some way.
 */
class ConcreteDecoratorA : public Decorator {
  /**
   * Decorators may call parent implementation of the operation, instead of
   * calling the wrapped object directly. This approach simplifies extension of
   * decorator classes.
   */
 public:
  ConcreteDecoratorA(Component* component) : Decorator(component) {
  }
  int Operation() const override {
    return Decorator::Operation() + 2;
  }
};
/**
 * Decorators can execute their behavior either before or after the call to a
 * wrapped object.
 */
class ConcreteDecoratorB : public Decorator {
 public:
  ConcreteDecoratorB(Component* component) : Decorator(component) {
  }

  int Operation() const override {
    return Decorator::Operation() + 3;
  }
};
/**
 * The client code works with all objects using the Component interface. This
 * way it can stay independent of the concrete classes of components it works
 * with.
 */
void ClientCode(Component* component) {
  // ...
  std::cout << "RESULT: " << component->Operation();
  // ...
}
void solve() {
	 Component* simple = new ConcreteComponent;
  cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";
  /**
   * ...as well as decorated ones.
   *
   * Note how decorators can wrap not only simple components but the other
   * decorators as well.
   */
  Component* decorator1 = new ConcreteDecoratorA(simple);
  Component* decorator2 = new ConcreteDecoratorB(decorator1);
  std::cout << "Client: Now I've got a decorated component:\n";
  ClientCode(decorator2);
  std::cout << "\n";
	
 
 }
int main()
{
#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);

#endif 
  int t;
 // cin>>t;
  t=1;
  
  while(t--)
  {
    solve();
    
  }
  return 0;
}