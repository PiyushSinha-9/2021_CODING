
int flipBit(int a) {

    int currLen = 0;
    int prevLen = 0;
    int maxLen = 0;
    string binaryRepr = "";

    while (a) {
        if (a % 2) {
            binaryRepr += "1";
        } else {
            binaryRepr += "0";
        }
        a /= 2;
    }

    reverse(binaryRepr.begin(), binaryRepr.end());

    int count = 0;
    int n = binaryRepr.length();

    for (int i = 0; i < n; i++) {
        if (binaryRepr[i] == '0') {
            count += 1;
        }
    }

    // Handling edge cases.
    if (count == 0) {
        return 1;
    } else if (count == n) {
        return n;
    }

    for (int i = 0; i < n; i++) {

        // If Current bit is a 1 then increment 'CURRLEN' by 1.
        if (binaryRepr[i] == '1') {
            currLen += 1;
        }

        // If Current bit is a 0 then check next bit of 'A'.
        else if (binaryRepr[i] == '0') {
            i += 1;

            // Update 'PREVLEN' to 0 (if next bit is 0) or 'CURRLEN' (if next bit is 1).
            if (i < n && binaryRepr[i] == '0') {
                prevLen = 0;
            } else {
                prevLen = currLen;
            }

            // If two consecutively bits are 0 then 'CURRLEN' also will be 0.
            currLen = 0;
            i -= 1;
        }

        // Update 'MAXLEN' if required. 
        maxLen = max(prevLen + currLen, maxLen);
    }

    // We can always have a sequence of at least one 1, which is the fliped bit.
    return maxLen + 1;

}