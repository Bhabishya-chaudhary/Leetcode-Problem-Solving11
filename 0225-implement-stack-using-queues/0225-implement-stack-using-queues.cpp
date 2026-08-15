class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
    }

    void push(int x) {
        // Put new element in q2
        q2.push(x);

        // Move all old elements behind x
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap queues
        swap(q1, q2);
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};