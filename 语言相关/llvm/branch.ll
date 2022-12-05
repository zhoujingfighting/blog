;define a customized function to branch

define i1 @main(i32 %a, i32 %b) {
entry:
    %0 = icmp uge i32 %a, %b
    br i1 %0, label %BBTrue, label %BBFalse
BBTrue:
    %1 = add i32 %a, 1
    %2 = icmp uge i32 %1, %b
    ret i1 %2
BBFalse:
    %3 = sub i32 %b, 4
    %4 = icmp uge i32 %3, %a
    ret i1 %4
}