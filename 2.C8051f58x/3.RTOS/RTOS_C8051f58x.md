<h1 style="color:rgb(110, 143, 220); text-align: center;">__________________Mini OS Kernel_____________________ </h1>

# Thread : 
- Thread : quá trình thực thi của 1 task 
- Thread bao gồm : 
    + Bộ thanh ghi CPU : R0-R7 , ACC, B, DPTR, IE, PSW và PC .
    + Bộ nhớ stack (chỉ nằm trong vùng [iRAM](../1.Basic_knowledge/CIP51.md#round-robinrr))
    + Chương trình để thực thi 
- Vì chỉ có 1 Core và iRAM rất nhỏ <br>
==> Phải liên tục chuyển đổi các thanh ghi và chuyển đổi dữ liệu qua lại iRAM <=> xRAM 
