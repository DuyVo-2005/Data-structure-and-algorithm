# 1. Định nghĩa cây
Cây là một cấu trúc dữ liệu gồm một tập hữu hạn các nút, giữa các nút có một quan hệ phân cấp gọi là quan hệ "cha - con". Có một nút đặc biệt gọi là gốc (root).
Có thể định nghĩa cây bằng các đệ quy như sau:
- Mỗi nút là một cây, nút đó cũng là gốc của cây ấy
- Nếu n là một nút và n1, n2, …, nk lần lượt là gốc của các cây T1, T2, …, Tk; các cây này đôi 
một không có nút chung. Thì nếu cho nút n trở thành cha của các nút n1, n2, …, nk ta sẽ được một cây mới T. Cây này có nút n là gốc còn các cây T1, T2, …, Tk trở thành các cây 
con (subtree) của gốc.
Để tiện, người ta còn cho phép tồn tại một cây không có nút nào mà ta gọi là cây rỗng (null 
tree).
Số các con của một nút được gọi là cấp của nút đó
Nút có cấp bằng 0 được gọi là nút lá (leaf) hay nút tận cùng.
Những nút không phải là lá được gọi là nút nhánh (branch)
Cấp cao nhất của một nút trên cây gọi là cấp của cây đó
Gốc của cây người ta gán cho số mức là 1, nếu nút cha có mức là i thì nút con sẽ có mức là i + 
- Chiều cao (height) hay chiều sâu (depth) của một cây là số mức lớn nhất của nút có trên cây 
đó.
Một tập hợp các cây phân biệt được gọi là rừng (forest), một cây cũng là một rừng. Nếu bỏ nút gốc trên cây thì sẽ tạo thành một rừng các cây con.
Ví dụ:
- Mục lục của một cuốn sách có cấu trúc cây: phần, chương, bài, mục, ...
- Cấu trúc thư mục trên đĩa cũng có cấu trúc cây, thư mục gốc có thể coi là gốc của cây đó 
với các cây con là các thư mục con và tệp nằm trên thư mục gốc.
- Gia phả của một họ tộc cũng có cấu trúc cây.
- Một biểu thức số học gồm các phép toán cộng, trừ, nhân, chia cũng có thể lưu trữ trong một cây mà các toán hạng được lưu trữ ở các nút lá, các toán tử được lưu trữ ở các nút nhánh, mỗi nhánh là một biểu thức con.
# 2. CÂY NHỊ PHÂN (BINARY TREE)
Nó có đặc điểm là mọi nút trên cây chỉ có tối đa hai nhánh con. Với một nút thì người ta cũng phân biệt cây con trái và cây con phải của nút đó. Cây nhị phân là cây có tính đến thứ tự của các nhánh con.
- Cây nhị phân suy biến (degenerate binary tree), 
các nút không phải là lá chỉ có một nhánh con: cây lệch phải, trái, zigzag
- Cây nhị phân hoàn chỉnh (complete binary tree): Nếu chiều cao của cây là h thì mọi nút có mức < h - 1 đều có đúng 2 nút con. Còn nếu mọi nút có mức ≤ h - 1 đều có đúng 2 nút con thì cây đó được gọi là cây nhị phân đầy đủ (full binary tree). Cây nhị phân đầy đủ là trường hợp riêng của cây nhị phân hoàn chỉnh.
Ta có thể thấy ngay những tính chất sau bằng phép chứng minh quy nạp: 
- Trong các cây nhị phân có cùng số lượng nút như nhau thì cây nhị phân suy biến có chiều cao lớn nhất, còn cây nhị phân hoàn chỉnh thì có chiều cao nhỏ nhất.
- Số lượng tối đa các nút trên mức i của cây nhị phân là 2^(i-1), tối thiểu là 1 (i ≥ 1). 
- Số lượng tối đa các nút trên một cây nhị phân có chiều cao h là 2^h-1, tối thiểu là h (h ≥ 1). 
- Cây nhị phân hoàn chỉnh có n nút thì chiều cao của nó là h = ⎣lg(n)⎦ + 1.
# 3. BIỂU DIỄN CÂY NHỊ PHÂN
## 3.1. Biểu diễn bằng mảng
-Cây nhị phân đầy đủ: dễ dàng đánh số cho các nút trên cây đó theo thứ tự lần lượt từ mức 1 trở đi, hết mức này đến mức khác và từ trái sang phải đối với các nút ở mỗi mức.
Với cách đánh số này, con của nút thứ i sẽ là các nút thứ 2i và 2i + 1. Cha của nút thứ j là nút j div 2. Từ đó có thể lưu trữ cây bằng một mảng T, nút thứ i của cây được lưu trữ bằng phần tử T[i].
- Cây nhị phân không đầy đủ: ta có thể thêm vào một số nút giả để được cây 
nhị phân đầy đủ, và gán những giá trị đặc biệt cho những phần tử trong mảng T tương ứng với 
những nút này (lãng phí bộ nhớ lưu trữ).
## 3.2. Biểu diễn bằng cấu trúc liên kết
mỗi nút của cây là một bản ghi (record) gồm 3 trường: 

- Trường Info: Chứa giá trị lưu tại nút đó 

- Trường Left: Chứa liên kết (con trỏ) tới nút con trái, tức là chứa một thông tin đủ để biết nút con trái của nút đó là nút nào, trong trường hợp không có nút con trái, trường này được gán một giá trị đặc biệt. 

- Trường Right: Chứa liên kết (con trỏ) tới nút con phải, tức là chứa một thông tin đủ để biết 
nút con phải của nút đó là nút nào, trong trường hợp không có nút con phải, trường này 
được gán một giá trị đặc biệt.
# 4. PHÉP DUYỆT CÂY NHỊ PHÂN
Phép xử lý các nút trên cây mà ta gọi chung là phép thăm (Visit) các nút một cách hệ thống 
sao cho mỗi nút chỉ được thăm một lần gọi là phép duyệt cây.
## 4.1. Duyệt theo thứ tự trước (preorder traversal)
Giá trị trong mỗi nút bất kỳ sẽ được liệt kê trước giá trị lưu trong hai nút con của nó
## 4.2. Duyệt theo thứ tự giữa (inorder traversal)
Giá trị trong mỗi nút bất kỳ sẽ được liệt kê sau giá trị lưu ở nút con trái và được liệt kê trước giá trị lưu ở nút con phải.
## 4.3. Duyệt theo thứ tự sau (postorder traversal)
Giá trị trong mỗi nút bất kỳ sẽ được liệt kê sau giá trị lưu 
ở hai nút con của nút đó
# 5. CÂY K_PHÂN 
Cây K_phân là một dạng cấu trúc cây mà mỗi nút trên cây có tối đa K nút con (có tính đến thứ tự của các nút con).
## 5.1 Biểu diễn cây K_phân bằng mảng
Có thể thêm vào cây K_phân một số nút giả để cho mỗi nút nhánh của cây K_phân đều có đúng K nút con, các nút con được xếp 
thứ tự từ nút con thứ nhất tới nút con thứ K, sau đó đánh số các nút trên cây K_phân bắt đầu từ 0 trở đi, bắt đầu từ mức 1, hết mức này đến mức khác và từ "trái qua phải" ở mỗi mức. Nút con thứ j của nút i là: i * K + j. Nút cha của nút x là nút (x - 1) div K. Ta có thể dùng một mảng T đánh số từ 0 để lưu các giá trị trên các nút: Giá trị tại nút thứ i được lưu trữ ở phần tử T[i].
## 5.2 Biểu diễn cây K_phân bằng cấu trúc liên kết
Mỗi nút của cây là một bản ghi (record) gồm hai trường:
- Trường Info: Chứa giá trị lưu trong nút đó.
- Trường Links: Là một mảng gồm K phần tử, phần tử thứ i chứa liên kết (con trỏ) tới nút 
con thứ i, trong trường hợp không có nút con thứ i thì Links[i] được gán một giá trị đặc biệt.
Đối với cây K_ phân, ta cũng chỉ cần giữ lại nút gốc, bởi từ nút gốc, đi theo các hướng liên 
kết có thể đi tới mọi nút khác.
# 6. CÂY TỔNG QUÁT
## 6.1. Biểu diễn cây tổng quát bằng mảng
Đánh số các nút trên cây bắt đầu từ 1 theo 
một thứ tự tuỳ ý. Giả sử cây có n nút thì ta sử dụng: 
- Một mảng Info[1..n], trong đó Info[i] là giá trị lưu trong nút thứ i.
- Một mảng Children được chia làm n đoạn, đoạn thứ i gồm một dãy liên tiếp các phần tử là chỉ số các nút con của nút i. Như vậy mảng Children sẽ chứa tất cả chỉ số của mọi nút con trên cây (ngoại trừ nút gốc) nên nó sẽ gồm n - 1 phần tử, lưu ý rằng khi chia mảng Children làm n đoạn thì sẽ có những đoạn rỗng (tương ứng với danh sách các nút con của một nút lá)
- Một mảng Head[1..n + 1], để đánh dấu vị trí cắt đoạn trong mảng Children: Head[i] là vịtrí đứng liền trước đoạn thứ i, hay nói cách khác: Đoạn con tính từ chỉ số Head[i] + 1 đến Head[i] của mảng Children chứa chỉ số các nút con của nút thứ i. Khi Head[i] = Head[i+1] có nghĩa là đoạn thứ i rỗng. Quy ước: Head[n+1] = n - 1.
- Một biến lưu chỉ số của nút gốc.
## 6.2. Lưu trữ cây tổng quát bằng cấu trúc liên kết
mỗi nút là một bản ghi (record) gồm ba 
trường: 

- Trường Info: Chứa giá trị lưu trong nút đó. 

- Trường FirstChild: Chứa liên kết (con trỏ) tới nút con đầu tiên của nút đó (con cả), trong trường hợp là nút lá (không có nút con), trường này được gán một giá trị đặc biệt.
- Trường Sibling: Chứa liên kết (con trỏ) tới nút em kế cận bên phải (nút cùng cha với nút đang xét, khi sắp thứ tự các con thì nút đó đứng liền sau nút đang xét). Trong trường hợp không có nút em kế cận bên phải, trường này được gán một giá trị đặc biệt.
# 7. 
