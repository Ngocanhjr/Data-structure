

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

/**
 * @brief Chuyển đổi một chuỗi văn bản thành chuỗi nhị phân (ASCII 8-bit).
 * @param text Chuỗi văn bản đầu vào.
 * @return Chuỗi nhị phân tương ứng.
 */
std::string text_to_bits(const std::string& text) {
    std::string binary_string = "";
    for (char c : text) {
        binary_string += std::bitset<8>(c).to_string();
    }
    return binary_string;
}

/**
 * @brief Hiển thị các tín hiệu số và tuần tự dưới dạng văn bản trên console.
 * @param bits Chuỗi nhị phân.
 */
void print_signals_as_text(const std::string& bits) {
    std::string nrz_text        = "NRZ-Level  : ";
    std::string manchester_text = "Manchester : ";
    std::string rz_text         = "RZ         : ";
    std::string ask_text        = "ASK        : ";
    std::string fsk_text        = "FSK        : ";
    std::string psk_text        = "PSK        : ";

    for (char bit : bits) {
        if (bit == '1') {
            nrz_text        += "¯¯¯"; // Mức cao
            manchester_text += "_|¯"; // Chuyển từ Thấp -> Cao
            rz_text         += "|-|"; // Xung
            ask_text        += "¯v_"; // Có sóng
            fsk_text        += "vVv"; // Tần số cao
            psk_text        += "~^~"; // Pha 0
        } else { // bit == '0'
            nrz_text        += "___"; // Mức thấp
            manchester_text += "¯|_"; // Chuyển từ Cao -> Thấp
            rz_text         += "___"; // Không xung
            ask_text        += "___"; // Không có sóng
            fsk_text        += "~^~"; // Tần số thấp
            psk_text        += "_^_"; // Pha 180 độ (π)
        }
    }
    std::cout << "\n--- Tín hiệu hiển thị trên Console ---\n";
    std::cout << "Tín hiệu số:\n";
    std::cout << nrz_text << std::endl;
    std::cout << manchester_text << std::endl;
    std::cout << rz_text << std::endl;
    std::cout << "\nTín hiệu tuần tự (biến điệu):\n";
    std::cout << ask_text << std::endl;
    std::cout << fsk_text << std::endl;
    std::cout << psk_text << std::endl;
    std::cout << "----------------------------------------\n";
}

int main() {
    std::string input_text;
    std::cout << "Nhập vào đoạn văn bản cần mã hóa: ";
    std::getline(std::cin, input_text);

    if (input_text.empty()) {
        std::cout << "Không có văn bản nào được nhập. Thoát chương trình.\n";
        return 1;
    }

    // Giới hạn văn bản để hiển thị trên console không quá dài
    const int max_chars = 8;
    std::string original_text = input_text;
    if (input_text.length() > max_chars) {
        input_text = input_text.substr(0, max_chars);
         std::cout << "Văn bản quá dài. Chỉ hiển thị tín hiệu cho " << max_chars << " ký tự đầu tiên: '"
                  << input_text << "'\n";
    }
    
    // Chuyển văn bản thành chuỗi bit
    std::string bit_sequence = text_to_bits(input_text);
    std::cout << "Chuỗi nhị phân tương ứng: " << bit_sequence << std::endl;

    // Hiển thị các tín hiệu dưới dạng văn bản
    print_signals_as_text(bit_sequence);

    return 0;
}