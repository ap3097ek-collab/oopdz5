#include <iostream>
using namespace std;

struct uzel {
    int data;
    uzel* next;

    uzel(int v) : data(v), next(nullptr) {}
};

class svasSpisok {
private:
    uzel* head;

public:
    svasSpisok() : head(nullptr) {}

    ~svasSpisok() {
        ochistit();
    }

    bool pustoi() const {
        return head == nullptr;
    }

    void dobavNachalo(int v) {
        uzel* n = new uzel(v);
        n->next = head;
        head = n;
    }

    void dobavKonec(int v) {
        uzel* n = new uzel(v);
        if (pustoi()) {
            head = n;
            return;
        }
        uzel* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = n;
    }

    void udalNachalo() {
        if (pustoi()) return;
        uzel* t = head;
        head = head->next;
        delete t;
    }

    bool udalZnachenie(int v) {
        if (pustoi()) return false;
        if (head->data == v) {
            udalNachalo();
            return true;
        }
        uzel* cur = head;
        while (cur->next != nullptr && cur->next->data != v) {
            cur = cur->next;
        }
        if (cur->next == nullptr) return false;
        uzel* t = cur->next;
        cur->next = cur->next->next;
        delete t;
        return true;
    }

    uzel* poiski(int v) {
        uzel* cur = head;
        while (cur != nullptr) {
            if (cur->data == v) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    void ochistit() {
        while (!pustoi()) {
            udalNachalo();
        }
    }

    void vivod() const {
        uzel* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    svasSpisok sp;

    sp.dobavKonec(10);
    sp.dobavKonec(20);
    sp.dobavNachalo(5);
    sp.dobavKonec(30);

    sp.vivod();

    sp.udalZnachenie(20);
    sp.vivod();

    uzel* f = sp.poiski(30);
    if (f) cout << "naideno\n";
    else cout << "net\n";

    return 0;
}