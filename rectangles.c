/*
 * Finding intersection of two rectangles.
 * Make an rectangle called ans:
 *  left: maximum of r1 and r2 left
 *  bottom: maximum of r1 and r2 bottom
 *  right: minimum of r1 and r2 right
 *  top: minumum of r1 and r2 top
 * Rectangle called ans is  the answer.
 */

/*
 * Repetition
 * Whenever you have discovered repetition while generalizing your algorithm,
 * it translates into a loop. Typically, if your repetition involves counting,
 * you will use a for loop. Otherwise, if you are sure you always want to do
 * the body at least once, a do-while is the most appropriate type. In other
 * cases (which typically align with steps like "as long as (something)..."
 * while loops are generally your best bet. If your algorithm calls for you to
 * "stop repeating things" or "stop counting" you will want to translate that
 * idea into a break statement. Meanwhile, if your algorithm calls for you to
 * skip the rest of the steps in the current repetition, and go back the start
 * of the loop, that translates into a continue statement.
 */


struct rect_t {
    float left;
    float bottom;
    float right;
    float top;
};
typedef struct rect_t rect;

rect intersection(rect r1, rect r2) {
    rect ans;
    ans.left = max(r1.left, r2.left);
    ans.bottom = max(r1.bottom, r1.bottom);
    ans.right = min(r1.right, r2.right);
    ans.top = min(r1.top, r2.top);
    return ans;
}
float max(float f1, float f2) {
    if (f1>f2) {
        return f1;
    }
    else return f2;
}

float min(float f1, float f2) {
    if (f1<f2) {
        return f1;
    }
    else return f2;
}
