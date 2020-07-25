import tensorflow_datasets as tfds
import matplotlib.pyplot as plt
import numpy as np

def load_data():
    # 从本地目录./mnist加载数据集
    #datasets, info = tfds.load(name='fashion_mnist', with_info=True, as_supervised=True, download=False, data_dir='./mnist')
    datasets, info = tfds.load(name='fashion_mnist', with_info=True, as_supervised=True, download=True, data_dir='./mnist')
    mnist_train, mnist_test = datasets['train'], datasets['test']

    train_images = []
    train_labels = []
    test_images = []
    test_labels = []

    for t_img, t_label in tfds.as_numpy(mnist_train):
        train_images.append(t_img)
        train_labels.append(t_label)
    
    for t_img, t_label in tfds.as_numpy(mnist_test):
        test_images.append(t_img)
        test_labels.append(t_label)
    
    train_images = np.array(train_images)
    train_labels = np.array(train_labels)
    test_images = np.array(test_images)
    test_labels = np.array(test_labels)
    return train_images, train_labels, test_images, test_labels

def draw_one_pic(train_image):
    plt.figure()
    plt.imshow(train_image.reshape(28,28))
    plt.colorbar()
    plt.grid(False)
    plt.show()

def draw_normalization_pic(train_images, train_labels, n):
    class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']
    plt.figure(figsize=(10,10))
    for i in range(n):
        plt.subplot(5,5,i+1)
        plt.xticks([])
        plt.yticks([])
        plt.grid(False)
        plt.imshow(train_images[i].reshape(28,28), cmap=plt.cm.binary)
        plt.xlabel(class_names[train_labels[i]])
    plt.show()

