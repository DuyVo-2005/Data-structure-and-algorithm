# SOFTWARE PROGRAMMING STEP
## 1. Xác định bài toán (Determine mathematics)
## 2. Tìm cấu trúc dữ liệu biểu diễn thuật toán (Find data structures)
## 3. Tìm thuật toán (Find algorithms)
- Tính đơn nghĩa
- Tính dừng
- Tính đúng
- Tính phổ dụng
- Tính khả thi
## 4. Lập trình (Programming)
## 5. Kiểm thử (Test)
- Chạy thử và tìm lỗi
- Xây dựng các bộ test
## 6. Tối ưu hoá chương trình (Optimization)
- Tính tin cậy
- Tính uyển chuyển
- Tính trong sáng
- Tính hữu hiệu
# CÁC KÝ PHÁP ĐỂ ĐÁNH GIÁ ĐỘ PHỨC TẠP TÍNH TOÁN
> Cho một giải thuật thực hiện trên dữ liệu với kích thước n. Giả sử T(n) là thời gian thực hiện 
một giải thuật đó, g(n) là một hàm xác định dương với mọi n. Khi đó ta nói độ phức tạp tính toán của giải thuật là:
- Θ(g(n)) nếu tồn tại các hằng số dương c1, c2 và n0 sao cho c1.g(n) ≤ f(n) ≤ c2.g(n) với mọi n ≥ n0 [Ký pháp Θ lớn (big-theta notation)]. Trong ký pháp Θ lớn, hàm g(.) được gọi là giới hạn chặt (asymptotically tight bound) của hàm T(.)
- O(g(n)) nếu tồn tại các hằng số dương c và n0 sao cho T(n) ≤ c.g(n) với mọi n ≥ n0 [ký pháp chữ O lớn (big-oh notation)]. Trong ký pháp chữ O lớn, hàm g(.) được gọi là giới hạn trên (asymptotic upper bound) của hàm T(.)
- Ω(g(n)) nếu tồn tại các hằng số dương c và n0 sao cho c.g(n) ≤ T(n) với mọi n ≥ n0. Ký hiệu này gọi là ký pháp Ω lớn (big-omega notation). Trong ký pháp Ω lớn, hàm g(.) được gọi là giới hạn dưới (asymptotic lower bound) của hàm T(.)
- o(g(n)) nếu với mọi hằng số dương c, tồn tại một hằng số dương n0 sao cho T(n) ≤ c.g(n) với mọi n ≥ n0. Ký pháp này gọi là ký pháp chữ o nhỏ (little-oh notation).
- ω(g(n)) nếu với mọi hằng số dương c, tồn tại một hằng số dương n0 sao cho c.g(n) ≤ T(n) với mọi n ≥ n0. Ký pháp này gọi là ký pháp ω nhỏ (little-omega notation)
> Lưu ý: không có ký pháp θ nhỏ
> Dễ thấy T(n) = Θ(g(n)) nếu và chỉ nếu T(n) = O(g(n)) và T(n) = Ω(g(n))
> Một số tính chất của các ký pháp đã nêu:
- Tính bắc cầu (tất cả)
- Tính phản xạ (ký pháp lớn)
- Tính đối xứng (chỉ theta lớn)
- Tính hoá vị đối xứng
 \+ f(n) = O(g(n)) nếu và chỉ nếu g(n) = Ω(f(n)).
 \+ f(n) = o(g(n)) nếu và chỉ nếu g(n) = ω(f(n)).
> Để dễ nhớ ta coi các ký pháp Ο, Ω, Θ, ο, ω lần lượt tương ứng với các phép so sánh ≤, ≥, =, <, >. Từ đó suy ra các tính chất trên.
# XÁC ĐỊNH ĐỘ PHỨC TẠP TÍNH TOÁN CỦA GIẢI THUẬT
- Qui tắc bỏ hằng số
- Quy tắc lấy max
- Quy tắc cộng
- Quy tắc nhân
- Định lý Master (Master Theorem)
