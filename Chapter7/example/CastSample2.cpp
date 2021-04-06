#include <iostream>
using namespace std;

class CShape {
public:
    CShape() { }
    virtual ~CShape() { }
    virtual void Draw() { cout << "CShape::Draw()" << endl; }
};

class CRectangle : public CShape {
public:
    virtual void Draw() { cout << "CRectangle::Draw()" << endl; }
};

class CCircle : public CShape {
public:
    virtual void Draw() { cout << "CCircle::Draw()" << endl; }
};

int main(int argc, char* argv[]) {

    cout << "���� ��ȣ�� �Է��ϼ���. [1:�簢��, 2:��]: " << endl;
    int nInput = 0;
    cin >> nInput;

    CShape *pShape = nullptr;
    if (nInput == 1) pShape = new CRectangle;
    else if (nInput == 2) pShape = new CCircle;
    else pShape = new CShape;

    // ���� ��
    pShape->Draw();

    // ���� ��
    CRectangle *pRect = dynamic_cast<CRectangle*>(pShape);
    if (pRect != NULL) cout << "CRectangle::Draw()" << endl;
    else {
        CCircle *pCircle = dynamic_cast<CCircle*>(pShape);
        if (pCircle != NULL) cout << "CCircle::Draw()" << endl;
        else cout << "CShpae::Draw()" << endl;
    }

    return 0;
}