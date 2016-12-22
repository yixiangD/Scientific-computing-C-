#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void LineCharCount(stringstream &buffer) {
    char ch = 0;
    int nlines = 0, nchars = 0, nws = 0, ntot = 0;
    while (!buffer.eof()) {
        buffer.get(ch);
        ntot += 1;
        if (ch == '\n')
            nlines += 1;
        int ws = buffer.peek();
        if (isblank(ws))
            nws += 1;
    }
    nchars = ntot  - nlines;
    cout << nlines << " lines" << endl;
    cout << nchars + 1 << " characters " << endl;
}

int main(int argc, char* argv[]) {
    // read filename into variable fname
    string fname;
    if (argv[1] != 0)
        fname = argv[1];
    else {
        cin >> fname;
    }

    stringstream buffer;
    ifstream file(fname);
    if (file) {
        buffer << file.rdbuf();
        file.close();
        LineCharCount(buffer);
    }
    else {
        cout << "Warning: file does not exist!" << endl;
    }
    return 0;
}

