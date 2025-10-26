typedef long long ll;
class Bank {
public:
    vector<ll> bal;

    Bank(vector<ll>& balance) {
        bal = balance;
    }

    bool valid(int acc) {
        return acc >= 1 && acc <= (int)bal.size();
    }

    bool transfer(int account1, int account2, ll money) {
        if (!valid(account1) || !valid(account2)) return false;
        account1--; account2--;
        if (bal[account1] < money) return false;
        bal[account1] -= money;
        bal[account2] += money;
        return true;
    }

    bool deposit(int account, ll money) {
        if (!valid(account)) return false;
        account--;
        bal[account] += money;
        return true;
    }

    bool withdraw(int account, ll money) {
        if (!valid(account)) return false;
        account--;
        if (bal[account] < money) return false;
        bal[account] -= money;
        return true;
    }
};
