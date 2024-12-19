# Clean code book
Tác giả của "Clean Code" là Robert Cecil Martin, còn được biết đến là một nhà phát triển phần mềm, tác giả, diễn giả và chuyên gia trong lĩnh vực lập trình (Agile and Extreme Programming).
Tác phẩm "Clean Code" của ông là một nguồn tư duy quan trọng về cách viết mã nguồn một cách sạch sẽ và dễ đọc. Xuất bản lần đầu vào năm 2008, cuốn sách này đã trở thành một nguồn tài nguyên kinh điển cho những người phát triển phần mềm, giúp họ hiểu rõ hơn về tầm quan trọng của việc duy trì mã nguồn sạch và tổ chức.
Nội dung cuốn sách trình bày khá rõ về ý nghĩa của việc viết code sạch và cung cấp những hướng dẫn cụ thể để thực hiện, giúp người đọc nhận thức được tầm quan trọng của việc duy trì mã nguồn trong dự án lâu dài và làm thế nào để giảm thiểu bug và vấn đề kỹ thuật về sau.
Theo nhiều đọc giả đánh giá thì đây là một quyển sách rất đáng để đọc, hoàn toàn phù hợp với đối tượng độc giả có thể bao gồm từ sinh viên mới bắt đầu học lập trình đến các nhà phát triển có kinh nghiệm muốn cải thiện chất lượng của công việc lập trình.
## CHƯƠNG 1: HẬU QUẢ
Code lỗi-code rối: có thể là code mắc lỗi cú pháp, lỗi logic(hay còn gọi là lỗi ngữ nghĩa, lỗi trình bày)
Nguyên nhân chủ yếu dẫn đến đề này thường: do đặt tên biến, tên hàm, chú thích không rõ,... . Khi mắc các lỗi này thì thường sẽ để lại hậu quả khá nghiêm trọng, đặc biệt khi bạn làm việc với 1 quy mô lớn khiến ta phải lãng phí thời gian trong việc phát hiện, xử lý lỗi, từ đó dẫn đến làm chậm sự phát triển của bản thân.
Nghiêm trọng hơn, Khi mà các bạn tham gia các dự án lớn hay làm việc với các đội nhóm, việc chậm trễ trong xử lí code lỗi cũng có thể kéo hiệu suất của cả đội code sẽ tuột dốc khi phải chờ mình khắc phục phần code lỗi đó .
Theo tác giả Robert Martin đánh giá: Đây không chỉ là câu chuyện về công sức, chi phí, mà đó còn là vấn đề sống còn của các lập trình viên chuyên nghiệp.
Vậy khi đảm bảo được tính sạch của code thì ta sẽ được lợi ích gì:
- Thứ nhất, code của bạn sẽ dễ bảo trì, sửa lỗi, lỗi khó lẩn tránh, sự phụ thuộc của các câu lệnh được giảm thiểu, không lôi kéo các lỗi khác.
- Thứ hai, code sẽ đơn giản rõ ràng, thể hiện đúng ý đồ của lập trình viên.
- Thứ ba, code sẽ có thể được đọc và phát triển thêm bởi những lập trình viên khác. 
## CHƯƠNG 2: Cách đặt tên các đối tượng như biến, hàm, lớp rõ ràng, phù hợp
### 2.1. Tên của biến, hàm, hoặc lớp phải trả lời tất cả những câu hỏi về nó. Nó phải cho bạn biết lý do nó tồn tại, nó làm được những gì, và dùng nó ra sao. Việc chọn tên thể hiện được mục đích có thể làm cho việc hiểu và thay đổi code dễ dàng hơn nhiều.
vd: Tên d không tiết lộ điều gì. Nó không gợi lên cảm giác gì về thời gian, cũng không liên quan gì đến ngày. Khuyến cáo không đặt theo cách này.
### 2.2. Thông thường thì khi ta định nghĩa các biến, các hàm, các lớp thì khả năng ta sử dụng lại các hàm các biến các lớp đó khá cao. Nên khi nó có 1 cái tên rõ ràng, không trùng lặp thì nó sẽ giúp bạn tìm kiếm các tên này khá đơn giản và cũng tránh gây nhầm lẫn với các đối tượng khác.
vd: đoạn code bên dưới bằng cách viết một lớp đơn giản cho các ô thay vì sử dụng các mảng kiểu int. Nó có thể bao gồm một hàm thể hiện được mục đích (gọi nó là isFlagged – được gắn cờ chẳng hạn) để giấu đi những con số trừu tượng.
### 2.3. Các cụm từ đầy đủ, có thể đọc được thì sẽ dễ để lại ấn tượng, thuận tiện cho việc ghi nhớ nên cũng khá khuyến khích các bạn đặt tên bằng những cái tên phát âm được.
