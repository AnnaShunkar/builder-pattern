#include <iostream>
using namespace std;

class Message {
private:
    string header;
    string body;
    string footer;
public:
    void setHeader(const string& h) { header = h; }
    void setBody(const string& b) { body = b; }
    void setFooter(const string& f) { footer = f; }

    void show() const {
        cout << header << endl;
        cout << body << endl;
        cout << footer << endl;
    }
};

// будівельник
class MessageBuilder {
private:
    Message* msg;
public:
    MessageBuilder() { msg = new Message(); }
    MessageBuilder& addHeader(const string& h) {
        msg->setHeader(h);
        return *this;
    }

    MessageBuilder& addBody(const string& b) {
        msg->setBody(b);
        return *this;
    }

    MessageBuilder& addFooter(const string& f) {
        msg->setFooter(f);
        return *this;
    }

    Message* build() {
        return msg;
    }
};

int main() {
    MessageBuilder builder;
    Message* message = builder
        .addHeader("=== Message ===")
        .addBody("builder pattern")
        .addFooter("=== Finish ===")
        .build();

    message->show();
    return 0;
}