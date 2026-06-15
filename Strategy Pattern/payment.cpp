#include <iostream>
using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete Strategies

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount
             << " using Credit Card." << endl;
    }
};

class PaypalPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount
             << " using PayPal." << endl;
    }
};

class CryptoPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount
             << " using Cryptocurrency." << endl;
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount
             << " using UPI." << endl;
    }
};

// Context

class PaymentProcessor {
private:
    PaymentStrategy* paymentMethod;

public:
    PaymentProcessor(PaymentStrategy* strategy) {
        paymentMethod = strategy;
    }

    void setPaymentMethod(PaymentStrategy* strategy) {
        paymentMethod = strategy;
    }

    void processPayment(double amount) {
        paymentMethod->pay(amount);
    }
};

int main() {

    PaymentProcessor processor(
        new CreditCardPayment()
    );

    processor.processPayment(5000);

    cout << "-------------------" << endl;

    processor.setPaymentMethod(
        new PaypalPayment()
    );

    processor.processPayment(2500);

    cout << "-------------------" << endl;

    processor.setPaymentMethod(
        new CryptoPayment()
    );

    processor.processPayment(10000);

    cout << "-------------------" << endl;

    processor.setPaymentMethod(
        new UpiPayment()
    );

    processor.processPayment(800);

    return 0;
}
