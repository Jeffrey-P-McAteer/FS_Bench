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

Thinkpad P14s USB-C SSD running Windows 11 with an NTFS filesystem

```
test_folder="C:\\Users\\Jeffrey\\Downloads\\test-space"
folder_device_path=TODO implement C:\Users\Jeffrey\FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 1m 47s 153.7ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 0.92600ms (max 131.11100ms min 0.31600ms deviation of 130.79500ms) to complete write+delete+write data (10,664.14687 megabytes per second, 15,800 files tested)
 .dll files averaged 1.11200ms (max 223.64600ms min 0.30700ms deviation of 223.33900ms) to complete write+delete+write data (9,330.03597 megabytes per second, 16,600 files tested)
 .txt files averaged 0.92800ms (max 207.40200ms min 0.31400ms deviation of 207.08800ms) to complete write+delete+write data (12,931.03448 megabytes per second, 19,200 files tested)
.json files averaged 1.39000ms (max 604.85300ms min 0.31300ms deviation of 604.54000ms) to complete write+delete+write data (7,059.35252 megabytes per second, 15,700 files tested)
  .so files averaged 1.12600ms (max 589.21700ms min 0.30200ms deviation of 588.91500ms) to complete write+delete+write data (9,713.58792 megabytes per second, 17,500 files tested)
 .bin files averaged 0.95800ms (max 192.54100ms min 0.31300ms deviation of 192.22800ms) to complete write+delete+write data (9,916.49269 megabytes per second, 15,200 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.61400ms (max 1.37700ms min 0.43700ms deviation of 0.94000ms) to complete write+delete+write data (16,083.06189 megabytes per second, 15,800 files tested)
 .dll files averaged 0.62300ms (max 1.39400ms min 0.44100ms deviation of 0.95300ms) to complete write+delete+write data (16,653.29053 megabytes per second, 16,600 files tested)
 .txt files averaged 0.61400ms (max 1.36800ms min 0.44100ms deviation of 0.92700ms) to complete write+delete+write data (19,543.97394 megabytes per second, 19,200 files tested)
.json files averaged 0.63600ms (max 1.43400ms min 0.44700ms deviation of 0.98700ms) to complete write+delete+write data (15,428.45912 megabytes per second, 15,700 files tested)
  .so files averaged 0.62100ms (max 1.38800ms min 0.44000ms deviation of 0.94800ms) to complete write+delete+write data (17,612.72142 megabytes per second, 17,500 files tested)
 .bin files averaged 0.61300ms (max 1.37400ms min 0.43900ms deviation of 0.93500ms) to complete write+delete+write data (15,497.55302 megabytes per second, 15,200 files tested)
test_is_anomalous=false
```

??? PC NVME drive running Windows 11 with an NTFS filesystem (w/ s + other interposers)

```
test_folder="C:\\Users\\jmcateer\\Downloads\\test-space"
folder_device_path=TODO implement FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 3m 43s 479.4ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 3.33500ms (max 296.94900ms min 2.32300ms deviation of 294.62600ms) to complete write+delete+write data (3,223.38831 megabytes per second, 17,200 files tested)
 .dll files averaged 2.33100ms (max 334.68900ms min 1.49800ms deviation of 333.19100ms) to complete write+delete+write data (4,424.06692 megabytes per second, 16,500 files tested)
 .txt files averaged 2.28800ms (max 370.61400ms min 1.43900ms deviation of 369.17500ms) to complete write+delete+write data (4,971.59091 megabytes per second, 18,200 files tested)
.json files averaged 1.56300ms (max 119.95600ms min 0.86100ms deviation of 119.09500ms) to complete write+delete+write data (6,517.91427 megabytes per second, 16,300 files tested)
  .so files averaged 1.61900ms (max 350.43800ms min 0.87400ms deviation of 349.56400ms) to complete write+delete+write data (6,639.90117 megabytes per second, 17,200 files tested)
 .bin files averaged 2.22700ms (max 53.79900ms min 1.44100ms deviation of 52.35800ms) to complete write+delete+write data (4,097.44050 megabytes per second, 14,600 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 2.53600ms (max 3.67300ms min 2.67500ms deviation of 0.99800ms) to complete write+delete+write data (4,238.95899 megabytes per second, 17,200 files tested)
 .dll files averaged 1.75600ms (max 2.65200ms min 1.76600ms deviation of 0.88600ms) to complete write+delete+write data (5,872.72210 megabytes per second, 16,500 files tested)
 .txt files averaged 1.70600ms (max 2.58100ms min 1.70500ms deviation of 0.87600ms) to complete write+delete+write data (6,667.64361 megabytes per second, 18,200 files tested)
.json files averaged 1.17800ms (max 1.89000ms min 1.08800ms deviation of 0.80200ms) to complete write+delete+write data (8,648.13243 megabytes per second, 16,300 files tested)
  .so files averaged 1.17300ms (max 1.89600ms min 1.08200ms deviation of 0.81400ms) to complete write+delete+write data (9,164.53538 megabytes per second, 17,200 files tested)
 .bin files averaged 1.70300ms (max 2.57300ms min 1.70300ms deviation of 0.87000ms) to complete write+delete+write data (5,358.19143 megabytes per second, 14,600 files tested)
test_is_anomalous=false
```

```
test_folder="C:\\Users\\jmcateer\\Downloads\\test-space"
folder_device_path=TODO implement FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 3m 58s 724.4ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 3.55800ms (max 751.66300ms min 2.27900ms deviation of 749.38400ms) to complete write+delete+write data (2,951.09612 megabytes per second, 16,800 files tested)
 .dll files averaged 2.44300ms (max 374.67100ms min 1.47200ms deviation of 373.19900ms) to complete write+delete+write data (3,863.07818 megabytes per second, 15,100 files tested)
 .txt files averaged 2.55000ms (max 2,403.52300ms min 1.42900ms deviation of 2,402.09400ms) to complete write+delete+write data (4,607.84314 megabytes per second, 18,800 files tested)
.json files averaged 1.62100ms (max 286.64400ms min 0.86400ms deviation of 285.78000ms) to complete write+delete+write data (6,516.03948 megabytes per second, 16,900 files tested)
  .so files averaged 1.77800ms (max 1,624.29100ms min 0.84400ms deviation of 1,623.44700ms) to complete write+delete+write data (6,221.87852 megabytes per second, 17,700 files tested)
 .bin files averaged 2.38800ms (max 578.35600ms min 1.46100ms deviation of 576.89500ms) to complete write+delete+write data (3,847.36181 megabytes per second, 14,700 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 2.54200ms (max 3.61200ms min 2.76800ms deviation of 0.84400ms) to complete write+delete+write data (4,130.60582 megabytes per second, 16,800 files tested)
 .dll files averaged 1.74900ms (max 2.56900ms min 1.83100ms deviation of 0.73800ms) to complete write+delete+write data (5,395.94054 megabytes per second, 15,100 files tested)
 .txt files averaged 1.69900ms (max 2.49800ms min 1.77200ms deviation of 0.72600ms) to complete write+delete+write data (6,915.83284 megabytes per second, 18,800 files tested)
.json files averaged 1.16000ms (max 1.78600ms min 1.13300ms deviation of 0.65300ms) to complete write+delete+write data (9,105.60345 megabytes per second, 16,900 files tested)
  .so files averaged 1.16200ms (max 1.81100ms min 1.13000ms deviation of 0.68100ms) to complete write+delete+write data (9,520.22375 megabytes per second, 17,700 files tested)
 .bin files averaged 1.69900ms (max 2.50100ms min 1.77400ms deviation of 0.72700ms) to complete write+delete+write data (5,407.59270 megabytes per second, 14,700 files tested)
test_is_anomalous=false
```

BeBox Mini-PC NVME Drive running Arch Linux with a BCacheFS filesystem

```
test_folder="/home/user/test-space"
folder_device_path=/dev/nvme0n1p2
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 0m 7s 405.8ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 0.06900ms (max 36.92600ms min 0.04200ms deviation of 36.88400ms) to complete write+delete+write data (91,875.00000 megabytes per second, 14,700 files tested)
 .dll files averaged 0.07500ms (max 38.67800ms min 0.04200ms deviation of 38.63600ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
 .txt files averaged 0.07200ms (max 37.47400ms min 0.04200ms deviation of 37.43200ms) to complete write+delete+write data (110,625.00000 megabytes per second, 17,700 files tested)
.json files averaged 0.07900ms (max 36.56100ms min 0.04200ms deviation of 36.51900ms) to complete write+delete+write data (101,875.00000 megabytes per second, 16,300 files tested)
  .so files averaged 0.07100ms (max 37.50200ms min 0.04100ms deviation of 37.46100ms) to complete write+delete+write data (112,500.00000 megabytes per second, 18,000 files tested)
 .bin files averaged 0.07400ms (max 38.51200ms min 0.04100ms deviation of 38.47100ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.03800ms (max 0.05700ms min 0.04500ms deviation of 0.01200ms) to complete write+delete+write data (91,875.00000 megabytes per second, 14,700 files tested)
 .dll files averaged 0.03800ms (max 0.05800ms min 0.04500ms deviation of 0.01300ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
 .txt files averaged 0.03800ms (max 0.05700ms min 0.04500ms deviation of 0.01200ms) to complete write+delete+write data (110,625.00000 megabytes per second, 17,700 files tested)
.json files averaged 0.03900ms (max 0.05900ms min 0.04500ms deviation of 0.01400ms) to complete write+delete+write data (101,875.00000 megabytes per second, 16,300 files tested)
  .so files averaged 0.03900ms (max 0.05900ms min 0.04500ms deviation of 0.01400ms) to complete write+delete+write data (112,500.00000 megabytes per second, 18,000 files tested)
 .bin files averaged 0.03800ms (max 0.05800ms min 0.04500ms deviation of 0.01300ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
test_is_anomalous=false
```


