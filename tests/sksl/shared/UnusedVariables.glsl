
out vec4 sk_FragColor;
vec4 main() {
    float b = 2.0;

    float d = 3.0;
    b++;
    d++;
    return vec4(float(b == 2.0), float(b == 3.0), float(d == 5.0), float(d == 4.0));
}