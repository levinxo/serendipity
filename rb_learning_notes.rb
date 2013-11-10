#!/usr/bin/env ruby

#-----------------------
# everything is object
# 点号之前的东西称为接收者，点号后面的名字是被调用的方法
# 方法通过向对象发送消息来唤起调用

def hello(name)
  "Hello, #{name.capitalize}"
end

puts hello('levin')
puts 'levin'.length
puts -8.abs
puts 'levin'.index('v')

#-----------------------
# array literal

words_array = ['cat', 'dog']
puts words_array

words_array = %w{cat dog}
puts words_array

#-----------------------
# hash literal
# 此处和php数组一样的结构

words_hash = {
  'a' => 'hello',
  'b' => 'world',
}

puts words_hash

#-----------------------
# control structures

if 5 > 3
  puts 'ret 1'
elsif 5 == 3
  puts 'ret 2'
else
  puts 'ret 3'
end

puts 'hello' if 1

square = 2
square = square*square while square < 100
puts square

#-----------------------
# regex

if 'ruby' =~ /r\w*y/
  puts 'match'
end

puts 'python'.sub(/python/, 'ruby')
puts 'pythonpython'.gsub(/python/, 'ruby')

#-----------------------
# block yield
# 迭代器反复调用block中的代码。迭代数组的each等方法中肯定使用了yield

def call_block
  yield('hello')
end

call_block { | word | puts word }   #两个竖线为管道符

words_array.each { | word | puts word }

5.times { print '*' }

3.upto(6) { |i| print i }

('a'..'e').each { |char| print char }

print "\n"

def fib_up_to(max)
  i1, i2 = 1, 1         #并行赋值
  while i1 < max
    yield i1
    i1, i2 = i2, i1+i2
  end
end

fib_up_to(1000) { |f| print f, ' ' }

a = [1, 2]
b = 'cat'
a.each { |b| c = b * a[1] }
puts b                  #=>2    why?为什么b等于2
puts defined?(c)

puts [1, 2, 'a', 'b'].collect { |x| x.succ }      #=>[2, 3, "b", "c"]    collect将数组元素传递给block，block返回的结果被用来生成一个新的数组。succ为后继的意思

#f = File.open('rb_learning_notes.rb')
#f.each do |line|
#  puts line
#end
#f.close

puts [1, 2, 3, 4].inject { |sum, ele| sum+ele }   #=>10
puts [1, 2, 3, 4].inject { |product, ele| product*ele }   #=>24

#-----------------------
# printf

printf("\nNum: %3.2f, String: %s\n", 237844.248, 'hello')

#-----------------------
# class object
# 创建对象时首先在内存中保存未初始化的对象，然后调用对象的initialize方法
# @符号开头的变量为实例变量，每个对象都有实例变量的拷贝
# 子类继承方法时，应该是增量，而不是直接检验或使用父类的实例变量(低耦合)

class Song
  
  attr_reader :name, :artist, :duration
  
  attr_writer :duration
  
  @@play_count = 0
  
  def initialize(name, artist, duration)
    @name = name
    @artist = artist
    @duration = duration
    @play_count = 0
  end

  def to_s
    "#@name, #@artist (#@duration)"
  end
  
  def play
    @@play_count += 1
    @play_count += 1
    "#@play_count plays, total #@@play_count plays"
  end
  
  public :to_s, :play
  
end

song = Song.new('ruby', 'ruby song', 240)
puts song.inspect
puts song.to_s

class OKSong < Song
  
  attr_reader :lyrics
  
  def initialize(name, artist, duration, lyrics)
    super(name, artist, duration)
    @lyrics = lyrics
  end

  def to_s
    super + " lyrics: #@lyrics"
  end
  
  public :to_s

end

song = OKSong.new('ruby', 'ruby song', 240, 'ruby song lyrics')
puts song.inspect
puts song.to_s
puts song.name
puts song.lyrics
puts song.duration
song.duration = 301
puts song.duration
puts song.play
puts song.play

class SongList
  
  MAX_TIME = 300
  
  def SongList.is_too_long(song)  #如果没加类名前缀，直接调用将提示没有这个方法
    return song.duration > MAX_TIME
  end
  
end

puts SongList.is_too_long(song)

#-----------------------
# variables
# 变量本身不是对象，变量是对象的引用，对象一般存在于heap中
# 变量可以通过freeze方法阻止被改动

a = 'Tim'
b = a
a[0] = 'J'
puts a
puts b

a = 'Tim'
b = a.dup
a[0] = 'J'
puts a
puts b

#-----------------------
# Array
# 使用[start, count]来访问数组
# 使用[start..end]或[start...end]访问数组，两个点表示包含end元素，三个点不包含end元素

a = ['a', 'b', 'c', 'd', 'e']

puts a[1, 2]

puts a[1..2]

puts a[1...2]

a[1] = [1, 2]           #=>["a", [1, 2], "c", "d", "e"]

a[1, 2] = 'cat'         #=>["a", "cat", "d", "e"]

a[1, 0] = 'dog'         #=>["a", "dog", "cat", "d", "e"]

a[1, 1] = ['b', 'c']    #=>["a", "b", "c", "cat", "d", "e"]

a[3..3] = []            #=>["a", "b", "c", "d", "e"]

a[7..8] = 'x', 'y'      #=>["a", "b", "c", "d", "e", nil, nil, "x", "y"]












