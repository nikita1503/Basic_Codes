typedef long long ll;
struct LL {
  ll value;
  static const ll MOD = 1000000007;

  LL(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  LL(long long a, long long b) : value(0){ *this += a; *this /= b;}

  LL& operator+=(LL const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  LL& operator-=(LL const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  LL& operator*=(LL const& b) {value = ((ll)value * b.value) % MOD;return *this;}
  LL& operator++(int) {LL tmp(*this); value += (ll)1; if (value >= MOD) value -= MOD; return tmp;}
  LL& operator--(int) {LL tmp(*this); value -= (ll)1; if (value < 0) value += MOD;return tmp;}

  friend LL pow_(LL a, ll e) { ll res = 1; while (e > 0) {if (e & 1) res = (res * a.value)%MOD; a = a * a;e >>= 1;} return LL(res); }
  friend LL inverse(LL a) { return pow_(a, MOD - 2); }

  LL& operator/=(LL const& b) { return *this *= inverse(b); }
  friend LL operator+(LL a, LL const b) { return a += b; }
  friend LL operator-(LL a, LL const b) { return a -= b; }
  friend LL operator-(LL const a) { return 0 - a; }
  friend LL operator*(LL a, LL const b) { return a *= b; }
  friend LL operator/(LL a, LL const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, LL const& a) {return os << a.value;}
  friend std::istream& operator>>(std::istream& is, LL & a) {ll x; is >> x; a+= LL(x); 
  return is;}
  friend bool operator==(LL const& a, LL const& b) {return a.value == b.value;}
  friend bool operator!=(LL const& a, LL const& b) {return a.value != b.value;}
  friend bool operator<(LL const& a, LL const& b) {return a.value < b.value;}
  friend bool operator<=(LL const& a, LL const& b) {return a.value <= b.value;}
  friend bool operator>(LL const& a, LL const& b) {return a.value > b.value;}
  friend bool operator>=(LL const& a, LL const& b) {return a.value >= b.value;}
};
