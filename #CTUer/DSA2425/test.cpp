#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <cmath>
#include <cstdlib> // For system()

// H?ng s? cho các tín hi?u tu?n t?
const int SAMPLES_PER_BIT = 200;
const double PI = 3.14159265358979323846;

/**
 * @brief Chuy?n d?i m?t chu?i van b?n thành chu?i nh? phân (ASCII 8-bit).
 * @param text Chu?i van b?n d?u vào.
 * @return Chu?i nh? phân tuong ?ng.
 */
std::string text_to_bits(const std::string& text) {
    std::string binary_string = "";
    for (char c : text) {
        binary_string += std::bitset<8>(c).to_string();
    }
    return binary_string;
}

/**
 * @brief T?o t?p d? li?u cho tín hi?u NRZ.
 * @param bits Chu?i nh? phân.
 */
void generate_nrz_data(const std::string& bits) {
    std::ofstream data_file("nrz_data.dat");
    for (int i = 0; i < bits.length(); ++i) {
        int level = (bits[i] == '1') ? 1 : -1;
        data_file << i << " " << level << "\n";
        data_file << (i + 1) << " " << level << "\n";
    }
    data_file.close();
}

/**
 * @brief T?o t?p d? li?u cho tín hi?u Manchester.
 * @param bits Chu?i nh? phân.
 */
void generate_manchester_data(const std::string& bits) {
    std::ofstream data_file("manchester_data.dat");
    for (int i = 0; i < bits.length(); ++i) {
        if (bits[i] == '1') { // Chuy?n t? Th?p -> Cao
            data_file << i << " " << -1 << "\n";
            data_file << i + 0.5 << " " << -1 << "\n";
            data_file << i + 0.5 << " " << 1 << "\n";
            data_file << i + 1 << " " << 1 << "\n";
        } else { // Chuy?n t? Cao -> Th?p
            data_file << i << " " << 1 << "\n";
            data_file << i + 0.5 << " " << 1 << "\n";
            data_file << i + 0.5 << " " << -1 << "\n";
            data_file << i + 1 << " " << -1 << "\n";
        }
    }
    data_file.close();
}

/**
 * @brief T?o t?p d? li?u cho tín hi?u ASK.
 * @param bits Chu?i nh? phân.
 */
void generate_ask_data(const std::string& bits) {
    std::ofstream data_file("ask_data.dat");
    double carrier_freq = 5.0;
    double time_step = 1.0 / SAMPLES_PER_BIT;
    for (int i = 0; i < bits.length(); ++i) {
        for (int j = 0; j < SAMPLES_PER_BIT; ++j) {
            double t = i + j * time_step;
            double amplitude = (bits[i] == '1') ? 1.0 : 0.0;
            double signal = amplitude * sin(2 * PI * carrier_freq * t);
            data_file << t << " " << signal << "\n";
        }
    }
    data_file.close();
}

/**
 * @brief T?o t?p d? li?u cho tín hi?u FSK.
 * @param bits Chu?i nh? phân.
 */
void generate_fsk_data(const std::string& bits) {
    std::ofstream data_file("fsk_data.dat");
    double freq_low = 5.0;
    double freq_high = 10.0;
    double time_step = 1.0 / SAMPLES_PER_BIT;
    for (int i = 0; i < bits.length(); ++i) {
        for (int j = 0; j < SAMPLES_PER_BIT; ++j) {
            double t = i + j * time_step;
            double freq = (bits[i] == '1') ? freq_high : freq_low;
            double signal = sin(2 * PI * freq * t);
            data_file << t << " " << signal << "\n";
        }
    }
    data_file.close();
}

/**
 * @brief T?o t?p d? li?u cho tín hi?u PSK.
 * @param bits Chu?i nh? phân.
 */
void generate_psk_data(const std::string& bits) {
    std::ofstream data_file("psk_data.dat");
    double carrier_freq = 5.0;
    double time_step = 1.0 / SAMPLES_PER_BIT;
    for (int i = 0; i < bits.length(); ++i) {
        for (int j = 0; j < SAMPLES_PER_BIT; ++j) {
            double t = i + j * time_step;
            double phase = (bits[i] == '1') ? 0.0 : PI;
            double signal = sin(2 * PI * carrier_freq * t + phase);
            data_file << t << " " << signal << "\n";
        }
    }
    data_file.close();
}

/**
 * @brief T?o k?ch b?n Gnuplot d? v? t?t c? các tín hi?u.
 * @param title Tiêu d? chính cho c?a s? d? th?.
 */
void generate_plot_script(const std::string& title) {
    std::ofstream script_file("plot_script.plt");
    script_file << "set terminal wxt size 1200,900 title '" << title << "'\n";
    script_file << "set multiplot layout 5,1 title 'Mã hóa và Bi?n di?u cho: " << title << "' font ',14'\n";
    script_file << "set grid xtics\n";
    script_file << "set key off\n"; // T?t chú thích (legend)

    // Plot NRZ
    script_file << "set title 'Tín hi?u s?: NRZ-Level'\n";
    script_file << "set xlabel 'Th?i gian'\n";
    script_file << "set ylabel 'Ði?n áp'\n";
    script_file << "plot 'nrz_data.dat' with steps\n";

    // Plot Manchester
    script_file << "set title 'Tín hi?u s?: Manchester'\n";
    script_file << "plot 'manchester_data.dat' with steps\n";

    // Plot ASK
    script_file << "set title 'Tín hi?u tu?n t?: Bi?n di?u cu?ng d? (ASK)'\n";
    script_file << "set ylabel 'Biên d?'\n";
    script_file << "plot 'ask_data.dat' with lines\n";

    // Plot FSK
    script_file << "set title 'Tín hi?u tu?n t?: Bi?n di?u t?n s? (FSK)'\n";
    script_file << "plot 'fsk_data.dat' with lines\n";

    // Plot PSK
    script_file << "set title 'Tín hi?u tu?n t?: Bi?n di?u pha (PSK)'\n";
    script_file << "plot 'psk_data.dat' with lines\n";

    script_file << "unset multiplot\n";
    script_file.close();
}

int main() {
    std::string input_text;
    std::cout << "Nh?p vào do?n van b?n c?n mã hóa: ";
    std::getline(std::cin, input_text);

    if (input_text.empty()) {
        std::cout << "Không có van b?n nào du?c nh?p. Thoát chuong trình.\n";
        return 1;
    }

    // Gi?i h?n van b?n d? bi?u d? không quá dài
    const int max_chars = 4;
    if (input_text.length() > max_chars) {
        std::cout << "Van b?n quá dài. Ch? hi?n th? tín hi?u cho " << max_chars << " ký t? d?u tiên: '"
                  << input_text.substr(0, max_chars) << "'\n";
        input_text = input_text.substr(0, max_chars);
    }

    // Chuy?n van b?n thành chu?i bit
    std::string bit_sequence = text_to_bits(input_text);
    std::cout << "Chu?i nh? phân tuong ?ng: " << bit_sequence << std::endl;

    // T?o các t?p d? li?u
    generate_nrz_data(bit_sequence);
    generate_manchester_data(bit_sequence);
    generate_ask_data(bit_sequence);
    generate_fsk_data(bit_sequence);
    generate_psk_data(bit_sequence);

    // T?o k?ch b?n Gnuplot
    std::string plot_title = "Van b?n: '" + input_text + "'";
    generate_plot_script(plot_title);

    // Th?c thi Gnuplot
    std::cout << "Ðang m? Gnuplot d? v? d? th?...\n";
    // L?nh "-persist" gi? cho c?a s? d? th? không b? dóng ngay l?p t?c
    system("gnuplot -persist plot_script.plt");

    return 0;
}