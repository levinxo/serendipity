# TensorFlow and tf.keras
import tensorflow as tf
import tensorflow_datasets as tfds
from tensorflow import keras
# Helper libraries
import numpy as np
import matplotlib.pyplot as plt
import util

# use tf2.2
print(tf.__version__)

# 加载数据集
train_images, train_labels, test_images, test_labels = util.load_data()

# 展示第一张图片
util.draw_one_pic(train_images[0])

# 归一化
train_images = train_images / 255.0
test_images = test_images / 255.0

# 展示归一化之后的图片
util.draw_normalization_pic(train_images[:25], train_labels[:25], 25);

# 构建模型
model = keras.Sequential([
    keras.layers.Conv2D(32, 3, activation='relu', input_shape=(28, 28, 1)),
    keras.layers.MaxPooling2D(),
    keras.layers.Flatten(),
    keras.layers.Dense(128, activation='relu'),
    keras.layers.Dense(10, activation='softmax')
])

# 设置损失函数和优化器
model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

# 训练
model.fit(train_images, train_labels, epochs=2)

# 评估
test_loss, test_acc = model.evaluate(test_images,  test_labels, verbose=2)


