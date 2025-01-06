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

Gaming PC with 3 different types of drives installed running Windows 10

```
test_folder="D:\\sata-magnetic-hdd-test-folder"
folder_device_path=TODO implement C:\Users\Jeffrey\FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 3m 0s 174.7ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 2.45500ms (max 1,648.66000ms min 0.42200ms deviation of 1,648.23800ms) to complete write+delete+write data (4,378.81874 megabytes per second, 17,200 files tested)
 .dll files averaged 1.33500ms (max 1,102.74800ms min 0.42600ms deviation of 1,102.32200ms) to complete write+delete+write data (7,584.26966 megabytes per second, 16,200 files tested)
 .txt files averaged 1.90100ms (max 1,363.32400ms min 0.42500ms deviation of 1,362.89900ms) to complete write+delete+write data (5,622.04103 megabytes per second, 17,100 files tested)
.json files averaged 1.67600ms (max 1,385.75400ms min 0.42400ms deviation of 1,385.33000ms) to complete write+delete+write data (5,780.13126 megabytes per second, 15,500 files tested)
  .so files averaged 1.80800ms (max 1,166.61600ms min 0.42300ms deviation of 1,166.19300ms) to complete write+delete+write data (5,980.36504 megabytes per second, 17,300 files tested)
 .bin files averaged 1.57800ms (max 1,116.93000ms min 0.42800ms deviation of 1,116.50200ms) to complete write+delete+write data (6,614.38530 megabytes per second, 16,700 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.49900ms (max 1.09600ms min 0.54500ms deviation of 0.55100ms) to complete write+delete+write data (21,543.08617 megabytes per second, 17,200 files tested)
 .dll files averaged 0.49300ms (max 0.86200ms min 0.54700ms deviation of 0.31500ms) to complete write+delete+write data (20,537.52535 megabytes per second, 16,200 files tested)
 .txt files averaged 0.49400ms (max 0.89300ms min 0.54700ms deviation of 0.34600ms) to complete write+delete+write data (21,634.61538 megabytes per second, 17,100 files tested)
.json files averaged 0.49300ms (max 0.86200ms min 0.54800ms deviation of 0.31400ms) to complete write+delete+write data (19,650.10142 megabytes per second, 15,500 files tested)
  .so files averaged 0.49500ms (max 0.91700ms min 0.54800ms deviation of 0.36900ms) to complete write+delete+write data (21,843.43434 megabytes per second, 17,300 files tested)
 .bin files averaged 0.49300ms (max 0.89000ms min 0.54700ms deviation of 0.34300ms) to complete write+delete+write data (21,171.39959 megabytes per second, 16,700 files tested)
test_is_anomalous=false



test_folder="F:\\usb-magnetic-hdd-test-folder"
folder_device_path=TODO implement C:\Users\Jeffrey\FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 7m 33s 715.8ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 4.41300ms (max 998.01800ms min 2.30700ms deviation of 995.71100ms) to complete write+delete+write data (2,464.30999 megabytes per second, 17,400 files tested)
 .dll files averaged 4.57500ms (max 1,355.26700ms min 2.30900ms deviation of 1,352.95800ms) to complete write+delete+write data (2,117.48634 megabytes per second, 15,500 files tested)
 .txt files averaged 4.52400ms (max 768.14200ms min 2.33400ms deviation of 765.80800ms) to complete write+delete+write data (2,348.58532 megabytes per second, 17,000 files tested)
.json files averaged 4.72900ms (max 877.86700ms min 2.38500ms deviation of 875.48200ms) to complete write+delete+write data (2,048.53034 megabytes per second, 15,500 files tested)
  .so files averaged 4.58600ms (max 1,271.64300ms min 2.34800ms deviation of 1,269.29500ms) to complete write+delete+write data (2,398.60445 megabytes per second, 17,600 files tested)
 .bin files averaged 4.41000ms (max 726.85200ms min 2.32000ms deviation of 724.53200ms) to complete write+delete+write data (2,409.29705 megabytes per second, 17,000 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 2.46200ms (max 3.58700ms min 2.67400ms deviation of 0.91300ms) to complete write+delete+write data (4,417.14054 megabytes per second, 17,400 files tested)
 .dll files averaged 2.46500ms (max 3.60000ms min 2.67900ms deviation of 0.92100ms) to complete write+delete+write data (3,930.02028 megabytes per second, 15,500 files tested)
 .txt files averaged 2.46400ms (max 3.59600ms min 2.67800ms deviation of 0.91800ms) to complete write+delete+write data (4,312.09416 megabytes per second, 17,000 files tested)
.json files averaged 2.53800ms (max 3.71200ms min 2.74400ms deviation of 0.96800ms) to complete write+delete+write data (3,816.98188 megabytes per second, 15,500 files tested)
  .so files averaged 2.46800ms (max 3.59600ms min 2.67900ms deviation of 0.91700ms) to complete write+delete+write data (4,457.05024 megabytes per second, 17,600 files tested)
 .bin files averaged 2.46700ms (max 3.59700ms min 2.67900ms deviation of 0.91800ms) to complete write+delete+write data (4,306.85043 megabytes per second, 17,000 files tested)
test_is_anomalous=false


test_folder="C:\\Users\\Jeffrey\\Downloads\\test-folder"
folder_device_path=TODO implement C:\Users\Jeffrey\FS_Bench\fs_bench_os_windows.hpp:6
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 5m 34s 94.1ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 3.36000ms (max 492.01100ms min 0.69100ms deviation of 491.32000ms) to complete write+delete+write data (3,199.40476 megabytes per second, 17,200 files tested)
 .dll files averaged 3.22000ms (max 2,662.93800ms min 0.67700ms deviation of 2,662.26100ms) to complete write+delete+write data (3,027.95031 megabytes per second, 15,600 files tested)
 .txt files averaged 3.21500ms (max 445.07500ms min 0.67200ms deviation of 444.40300ms) to complete write+delete+write data (3,479.78227 megabytes per second, 17,900 files tested)
.json files averaged 3.44700ms (max 744.81500ms min 0.69400ms deviation of 744.12100ms) to complete write+delete+write data (2,701.62460 megabytes per second, 14,900 files tested)
  .so files averaged 3.49800ms (max 497.71700ms min 0.67100ms deviation of 497.04600ms) to complete write+delete+write data (2,948.11321 megabytes per second, 16,500 files tested)
 .bin files averaged 3.29500ms (max 1,246.32100ms min 0.67400ms deviation of 1,245.64700ms) to complete write+delete+write data (3,395.29590 megabytes per second, 17,900 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.83900ms (max 1.58600ms min 0.84500ms deviation of 0.74100ms) to complete write+delete+write data (12,812.87247 megabytes per second, 17,200 files tested)
 .dll files averaged 0.83700ms (max 1.58500ms min 0.84800ms deviation of 0.73700ms) to complete write+delete+write data (11,648.74552 megabytes per second, 15,600 files tested)
 .txt files averaged 0.83800ms (max 1.57500ms min 0.84200ms deviation of 0.73300ms) to complete write+delete+write data (13,350.23866 megabytes per second, 17,900 files tested)
.json files averaged 0.85500ms (max 1.61700ms min 0.85800ms deviation of 0.75900ms) to complete write+delete+write data (10,891.81287 megabytes per second, 14,900 files tested)
  .so files averaged 0.84000ms (max 1.59800ms min 0.84700ms deviation of 0.75100ms) to complete write+delete+write data (12,276.78571 megabytes per second, 16,500 files tested)
 .bin files averaged 0.83500ms (max 1.57500ms min 0.84700ms deviation of 0.72800ms) to complete write+delete+write data (13,398.20359 megabytes per second, 17,900 files tested)
test_is_anomalous=false

```

Windows 11 on NVME SSD through Thunderbolt cable, with histogram graphs

```
test_folder="C:\\Users\\Jeffrey\\Downloads\\test-data"
folder_device_path=TODO implement C:\Users\Jeffrey\FS_Bench\fs_bench_os_windows.hpp:6
Creating 100 folders which will each have 1,000 files of various extensions containing 65,536 bytes of data written to them, file will be deleted, finally file will be written again.
If deletion fails OR writing to file fails, test is flagged as anomalous because the timing data is now useless (ie we did not measure what we wanted to b/c an I/O operation failed)
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 1m 57s 867.0ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 1.06600ms (min 0.34200ms max 110.04100ms deviation of 109.69900ms) to complete write+delete+write data (10,612.10131 megabytes per second, 18,100 files tested)
*
*
*
*
*

 .dll files averaged 1.25000ms (min 0.33600ms max 281.77500ms deviation of 281.43900ms) to complete write+delete+write data (8,300.00000 megabytes per second, 16,600 files tested)
*
*
*
*
*

 .txt files averaged 1.07400ms (min 0.32900ms max 60.00500ms deviation of 59.67600ms) to complete write+delete+write data (9,834.72998 megabytes per second, 16,900 files tested)
*
**
**
**
**

.json files averaged 1.16500ms (min 0.34800ms max 145.97800ms deviation of 145.63000ms) to complete write+delete+write data (7,832.61803 megabytes per second, 14,600 files tested)
*
*
*
*
*

  .so files averaged 1.29500ms (min 0.33700ms max 142.60400ms deviation of 142.26700ms) to complete write+delete+write data (8,542.47104 megabytes per second, 17,700 files tested)
*
*
*
*
*

 .bin files averaged 1.21500ms (min 0.34400ms max 151.70000ms deviation of 151.35600ms) to complete write+delete+write data (8,281.89300 megabytes per second, 16,100 files tested)
*
*
*
*
*

= = = = Trimmed Distribution MIN/MAX Report (removes statistical outlier figures at first+last 2% of values) = = = =
 .exe files averaged 0.80500ms (min 0.38700ms max 7.37600ms deviation of 6.98900ms) to complete write+delete+write data (13,431.67702 megabytes per second, 17,300 files tested)
    *
   ****
  ******
 *********
**************

 .dll files averaged 0.84000ms (min 0.39000ms max 8.53800ms deviation of 8.14800ms) to complete write+delete+write data (11,830.35714 megabytes per second, 15,900 files tested)
   *
  ****
 ******
 *******
************

 .txt files averaged 0.80300ms (min 0.38700ms max 7.62500ms deviation of 7.23800ms) to complete write+delete+write data (12,608.96638 megabytes per second, 16,200 files tested)
    *
   ****
  ******
 *********
**************

.json files averaged 0.83300ms (min 0.39600ms max 8.13500ms deviation of 7.73900ms) to complete write+delete+write data (10,504.20168 megabytes per second, 14,000 files tested)
   *
  ****
 ******
 ********
************

  .so files averaged 0.85100ms (min 0.38900ms max 8.79400ms deviation of 8.40500ms) to complete write+delete+write data (12,411.86839 megabytes per second, 16,900 files tested)
   *
  ***
 ******
 *******
***********

 .bin files averaged 0.83700ms (min 0.38800ms max 8.62800ms deviation of 8.24000ms) to complete write+delete+write data (11,499.40263 megabytes per second, 15,400 files tested)
   *
  ****
 ******
 *******
************
```

Arch Linux on NVME with Histograms

```
test_folder="/j/downloads/test-space"
folder_device_path=/dev/nvme0n1p3
Creating 100 folders which will each have 1,000 files of various extensions containing 65,536 bytes of data written to them, file will be deleted, finally file will be written again.
If deletion fails OR writing to file fails, test is flagged as anomalous because the timing data is now useless (ie we did not measure what we wanted to b/c an I/O operation failed)
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 0m 4s 660.7ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 0.04600ms (min 0.03500ms max 1.93600ms deviation of 1.90100ms) to complete write+delete+write data (111,875.00000 megabytes per second, 17,900 files tested)
▄▉▆▂▁
 .dll files averaged 0.04600ms (min 0.03500ms max 1.37900ms deviation of 1.34400ms) to complete write+delete+write data (110,000.00000 megabytes per second, 17,600 files tested)
▂█▉█▅▂▁▁
 .txt files averaged 0.04600ms (min 0.03500ms max 0.94800ms deviation of 0.91300ms) to complete write+delete+write data (99,375.00000 megabytes per second, 15,900 files tested)
▁▆▉▉▉█▅▃▂▁▁▁▁▁
.json files averaged 0.04600ms (min 0.03500ms max 2.06800ms deviation of 2.03300ms) to complete write+delete+write data (103,750.00000 megabytes per second, 16,600 files tested)
▄▉▆▂▁
  .so files averaged 0.04600ms (min 0.03500ms max 1.17200ms deviation of 1.13700ms) to complete write+delete+write data (108,125.00000 megabytes per second, 17,300 files tested)
▁▅▉▉▉▇▅▃▂▁▁▁
 .bin files averaged 0.04600ms (min 0.03500ms max 1.73300ms deviation of 1.69800ms) to complete write+delete+write data (91,875.00000 megabytes per second, 14,700 files tested)
▄▉▉▅▂▁
= = = = Trimmed Distribution MIN/MAX Report (removes statistical outlier figures at first+last 2% of values) = = = =
 .exe files averaged 0.04500ms (min 0.03700ms max 0.08000ms deviation of 0.04300ms) to complete write+delete+write data (106,875.00000 megabytes per second, 17,100 files tested)
▆▉▉▆▃▂▁
 .dll files averaged 0.04500ms (min 0.03700ms max 0.08200ms deviation of 0.04500ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
▇▉▆▃▁
 .txt files averaged 0.04500ms (min 0.03700ms max 0.08100ms deviation of 0.04400ms) to complete write+delete+write data (95,000.00000 megabytes per second, 15,200 files tested)
▇▉▉▆▃▂▁
.json files averaged 0.04500ms (min 0.03700ms max 0.07900ms deviation of 0.04200ms) to complete write+delete+write data (99,375.00000 megabytes per second, 15,900 files tested)
▆▉▉▆▃▂▁
  .so files averaged 0.04400ms (min 0.03700ms max 0.08000ms deviation of 0.04300ms) to complete write+delete+write data (103,750.00000 megabytes per second, 16,600 files tested)
▆▉▉▅▃▁▁
 .bin files averaged 0.04500ms (min 0.03700ms max 0.07600ms deviation of 0.03900ms) to complete write+delete+write data (88,125.00000 megabytes per second, 14,100 files tested)
▇▉▉▆▃▂▁
test_is_anomalous=false
```




