# FS_Bench

FS_Bench measures how closely your application-level filesystem performance is to hardware performance.

Many things can degrade the performance of an operating system, none so fatal as accidentially configuring a bad filesystem.

# Building

For Windows:

```bash
.\build.bat
```

For Linux + Mac

```bash
./build.sh
```


# Running

```bash

```

# Measured numbers from hardware configurations

Thinkpad P14s NVME drive running Arch Linux with the BTRFS filesystem

```
test_folder="/j/downloads/test-space"
folder_device_path=/dev/nvme1n1p3
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 0m 4s 548.1ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 0.04500ms (max 0.68300ms min 0.03500ms deviation of 0.64800ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
 .dll files averaged 0.04500ms (max 0.99400ms min 0.03500ms deviation of 0.95900ms) to complete write+delete+write data (115,625.00000 megabytes per second, 18,500 files tested)
 .txt files averaged 0.04500ms (max 0.42500ms min 0.03500ms deviation of 0.39000ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
.json files averaged 0.04500ms (max 0.41900ms min 0.03500ms deviation of 0.38400ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
  .so files averaged 0.04500ms (max 1.01700ms min 0.03500ms deviation of 0.98200ms) to complete write+delete+write data (107,500.00000 megabytes per second, 17,200 files tested)
 .bin files averaged 0.04500ms (max 1.40800ms min 0.03500ms deviation of 1.37300ms) to complete write+delete+write data (90,625.00000 megabytes per second, 14,500 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
 .dll files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (115,625.00000 megabytes per second, 18,500 files tested)
 .txt files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
.json files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
  .so files averaged 0.03400ms (max 0.05100ms min 0.03800ms deviation of 0.01300ms) to complete write+delete+write data (107,500.00000 megabytes per second, 17,200 files tested)
 .bin files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (90,625.00000 megabytes per second, 14,500 files tested)
test_is_anomalous=false
```

QEMU VM running Windows 11 from an NVME drive connected to a thunderbolt port with an NTFS filesystem

```
test_folder="C:\\Users\\Jeffrey\\Downloads\\test-space"
folder_device_path=TODO implement C:\Users\Jeffrey\FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 1m 51s 69.4ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 1.09800ms (max 188.91800ms min 0.35000ms deviation of 188.56800ms) to complete write+delete+write data (9,392.07650 megabytes per second, 16,500 files tested)
 .dll files averaged 1.10900ms (max 163.61700ms min 0.34300ms deviation of 163.27400ms) to complete write+delete+write data (10,087.91704 megabytes per second, 17,900 files tested)
 .txt files averaged 1.23800ms (max 165.78200ms min 0.34000ms deviation of 165.44200ms) to complete write+delete+write data (7,471.72859 megabytes per second, 14,800 files tested)
.json files averaged 1.18100ms (max 135.98900ms min 0.34700ms deviation of 135.64200ms) to complete write+delete+write data (8,414.47925 megabytes per second, 15,900 files tested)
  .so files averaged 1.00300ms (max 65.61900ms min 0.34800ms deviation of 65.27100ms) to complete write+delete+write data (12,088.73380 megabytes per second, 19,400 files tested)
 .bin files averaged 1.04900ms (max 177.92000ms min 0.34500ms deviation of 177.57500ms) to complete write+delete+write data (9,234.98570 megabytes per second, 15,500 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.44200ms (max 1.22100ms min 0.42400ms deviation of 0.79700ms) to complete write+delete+write data (23,331.44796 megabytes per second, 16,500 files tested)
 .dll files averaged 0.43800ms (max 1.18900ms min 0.42300ms deviation of 0.76600ms) to complete write+delete+write data (25,542.23744 megabytes per second, 17,900 files tested)
 .txt files averaged 0.44900ms (max 1.45700ms min 0.42400ms deviation of 1.03300ms) to complete write+delete+write data (20,601.33630 megabytes per second, 14,800 files tested)
.json files averaged 0.45300ms (max 1.33000ms min 0.43000ms deviation of 0.90000ms) to complete write+delete+write data (21,937.08609 megabytes per second, 15,900 files tested)
  .so files averaged 0.43800ms (max 1.14400ms min 0.42500ms deviation of 0.71900ms) to complete write+delete+write data (27,682.64840 megabytes per second, 19,400 files tested)
 .bin files averaged 0.43300ms (max 1.05800ms min 0.42400ms deviation of 0.63400ms) to complete write+delete+write data (22,372.97921 megabytes per second, 15,500 files tested)
test_is_anomalous=false
```


