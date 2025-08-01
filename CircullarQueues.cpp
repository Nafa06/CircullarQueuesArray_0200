
/**
 * @mainpage Documentation Project Circular Queues
 * @section Introduction
 * Projek ini merupakan projek struktur data
 * Menggunakan struktur data queues dengan pendekatan circular array.abort
 * @section Operations
 * Projek ini memiliki beberapa operasi diantaranya:
 * - Insert
 * - Delete
 * - Display
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * - Enqueue
 * - Dequeue
 * - Display
 * - Exit
 * 
 * @author Profile
 * - Nama : Muhammad Naufal Anggardi
 * - NIM  : 20240140200
 * - Kelas: D
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Demo@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief Class ini untuk operasi lengkap queues
 * 
 * 
 */


class Queues
{
private:
    int FRONT; ///< Variable private front untuk menyimpan posisi depan antrean
    int REAR; ///< Variable private rear untuk menyimpan posisi belakang antrean
    int max = 5; ///< Variabel private max untuk menyimpan ukuran maksimum antrian
    int queue_array[5]; ///< queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues object
     * Set default queues NULL 
     * with FRONT = -1 and REAR = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief Method untuk memasukkan data ke dalam antrian
     * Data dimasukkan ke variabel queue_array pada posisi REAR.
     */
    void insert()
    {
        int num; ///< Variable num untuk menyimpan nilai yang akan dimasukkan ke dalam antrian
        cout << "Enter a number to insert: ";
        cin >> num;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; // 1.a
            cout << endl;
            cout << endl;
            return; // 1.b
        }

        // 2. cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0;  // 2.b
        }
        else
        {
            // Jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief Method untuk menghapus data dari antrian
     * Data dihapus dari posisi FRONT pada antrian.
     */
    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "\nQueue underflow\n";
            cout << endl;

            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";
        cout << endl;
        // Cek apakah antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief Method untuk menampilkan elemen dalam antrian
     * Menampilkan elemen dari posisi FRONT hingga REAR.
     */
    void display()
    {
        int FRONT_position = FRONT; ///< Variable untuk menyimpan posisi depan antrean
        int REAR_position = REAR; ///< Variable untuk menyimpan posisi belakang antrean

        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            cout << endl;
            return;
        }

        cout << "\nElements in the queue are...\n";


        // Jika FRONT_position <= REAR_position, iterasi dari FRONT ke REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "    ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT_position > REAR_position, iterasi dari FRONT ke hingga array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "    ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "    ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief Main function untuk menjalankan program
 * Menampilkan menu
 */
int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered" << endl;
        }
    }
}