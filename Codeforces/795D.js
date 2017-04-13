function main() {
    var line = readline().split(" ");
    var n = parseInt(line[0]);
    var l = parseInt(line[1]) - 1;
    var r = parseInt(line[2]) - 1;

    line = readline();
    var a = line.split(" ");
    a.forEach(function(x, i) {
        a[i] = parseInt(a[i]);
    });

    line = readline();
    var b = line.split(" ");
    b.forEach(function(x, i) {
        b[i] = parseInt(b[i]);
    });

    for (var i = 0; i < l; ++i) {
        if (a[i] != b[i]) {
            print("LIE");
            return;
        }
    }

    for (var i = r + 1; i < n; ++i) {
        if (a[i] != b[i]) {
            print("LIE");
            return;
        }
    }

    print("TRUTH");
}

main();
