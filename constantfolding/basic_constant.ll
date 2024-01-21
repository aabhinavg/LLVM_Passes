define i32 @basic_math_operation(i32 %number){
    %add_fold = add i32 4,5
    %add_result = add i32 %add_fold,%number
    %sub_result = sub i32 %add_result, 5
    %mul_result = mul i32 %sub_result, 2
    %div_result = sdiv i32 %mul_result, 2
    ret i32 %div_result
}

define i32 @main() {
    %number = add i32 4, 5
    %result = call i32 @basic_math_operation(i32 %number)
    ret i32 %result
}
